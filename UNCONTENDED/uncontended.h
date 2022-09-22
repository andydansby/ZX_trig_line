#ifndef UNCONTENDED_H
#define UNCONTENDED_H

#include "non_working.h"


//UNCONTENDED RAM

//https://developer.download.nvidia.com/cg/abs.html


void dummyWait(void)
{
    for (temp5=0; temp5 < 4000; temp5++)
    {    }
}

/*
void degree2radian (void)
{
    radians = (float)degrees * ( PI / 180.0 );
}


void radian2degree (void)
{
    degrees = radians * ( 180 / PI );
}*/





///////////////////////////////////////////


float wrap (float xx )
{
    return xx - 6.28 * floor(xx / 6.28 + 0.5);//          1 = 4180 to 10 = 4680
}



//http://lab.polygonal.de/2007/07/18/fast-and-accurate-sinecosine-approximation/
//good from -PI to PI
float _mikeSIN (float xx)
{
    const float B = 1.273;    //  4/PI;
    const float C = 0.405;  //-4/(PI*PI);
    float sin, BCalc, CCalc;
    //float powX = xx * xx;

    if (xx < -3.14)
        xx += 6.28;
    else
    if (xx > 3.14)
        xx-=6.28;

    CCalc = C * xx * xx;
    BCalc = B * xx;

    if (xx < 0)
        sin = BCalc + CCalc;
    else
        sin = BCalc - CCalc;

    return sin;
}

float _mikeCOS (float xx)
{
    return _mikeSIN(1.57 - xx);
}


//https://www.gamedev.net/forums/topic/621589-extremely-fast-sin-approximation/

//Horner method
//https://web.archive.org/web/20160313140614/http://www.research.scea.com/gdc2003/fast-math-functions_p2.pdf
/*
float _damnSin (float xx)
{
    const float Alpha = 0.166;
    const float Beta = 0.0083;
    const float Gamma = 0.0001;
    float calc;
    float x2 = xx * xx;


    //calc = xx * (Gamma + x2 * (Beta + Alpha * x2));
    //calc = Alpha + (Beta * xx) - (Gamma * x2);
    //calc = xx - (Alpha * x3) + (Beta * x5) - (Gamma * x7);
    calc = (((Gamma * x2 + Beta)* x2+ Alpha)* x2 + 1) * xx;
    return calc;
}

float _damnCos(float xx)
{
    float calc = _damnSin(1.57 - xx);
    return calc;
    //return _mikeSIN(1.57 - xx);
}
*/


/*
float _oneCoderSIN (float xx)
{
    float j;

    if (xx < -3.14)
        xx += 6.28;
    else
    if (xx > 3.14)
        xx-=6.28;

    j = xx * 0.15915;
    //j = j - ((int) j);
    j = j - (floor(j));

    return 20.785 * j * (j - 0.5) * (j - 1.0);
}

float _oneCoderCOS (float xx)
{
    return _oneCoderSIN(1.57 - xx);
}
*/


/*
float xxxcos(float x)
{
    //constexpr T tp = 1./(2.*M_PI);
    const float tp = 0.16;

    x *= tp;
    //x -= .25 + x + .25;
    x -= .25 + floor(x + .25);
    x *= 16 * (ABS(x) - .5);
    return x;
}

float xxxsin(float x)
{
    return xxxcos(x + .157);
}
*/

/*
float sineStuff_sin(float xx)
{
	#define ABS(N) ((N<0)?(-N):(N))
	float yy;
	float B = 1.273;        //4/PI;
	float C = -0.405;       //-4/(PI*PI);
	float recip2 = 0.1592;  //1 / (PI * 2);
	float pi2 = 6.28;        //PI * 2;


	//convert the input value to a range of 0 to 1
	xx = (xx + 3.14) * recip2;
	//make it loop
	xx -= (long)(xx-(xx<0));
	//convert back from 0-1 to -pi to +pi.
	xx = (xx * pi2) - 3.14;
	//original function
	yy = B * xx + C * xx * ABS(xx);
	return (yy);
}

float sineStuff_cos (float xx)
{
	return sineStuff_sin(xx + 1.57);
}
*/


//attention, need -lm in the compiling string
float _sin_Smile(float xx)
{
	//http://devmaster.net/posts/9648/fast-and-accurate-sine-cosine
    //this routine was found by user Smile, don't know where
    //the algorithm comes from
    //pretty fast
    #define ABS(N) ((N<0)?(-N):(N))

    const float A = 7.5894;//A = 16 * sqrt(P);
    const float B = 1.6338;//B = (1 - P) / sqrt(P);
    const float C = 0.157; //.157 = HALFPI, move decimal point left 1
    int floor_x;

    float xxx = xx * C;
    floor_x = (int) (xxx + .5);
    //xxx = xxx - (float) floor_x;
    xxx = xxx - floor_x;
	xxx = A * xxx * (0.5 - ABS(xxx));
	return xxx * (B + ABS(xxx));
}

float _cos_Smile (float xx)
{
	return _sin_Smile(xx + 1.57);
}

float sine(float xx)
{
    const float B = 1.273;   //4/PI;
    const float C = -0.405;  //-4/(PI*PI);
    const float recip2 = 0.159; //1 / (PI * 2);
    const float pi2 = 6.28; //PI * 2;
    float yy;
    //convert the input value to a range of 0 to 1
    xx = (xx + PI) * recip2;
    //make it loop
    xx -= (long)(xx);
    //convert back from 0-1 to -pi to +pi.
    xx = (xx * pi2) - PI;
    //original function
    yy = (B * xx + C * xx * ABS(xx));
    return yy;
}

float cosine(float xx)
{
    const float B = 1.273;   //4/PI;
    const float C = -0.405;  //-4/(PI*PI);
    float yy;
    const float recip2 = 0.159; //1 / (PI * 2);
    const float pi2 = 6.28;     //PI * 2;
    const float hpi=1.57;       //PI/2;


    xx+=hpi; //shift for cosine
    xx = (xx + PI) * recip2;
    xx -= (long)(xx);
    //x-=(long)x
    //x -= (long)(x-(x\<0));
    xx = (xx * pi2) - PI;
    yy = (B * xx + C * xx * ABS(xx));
    return (yy);
}

float cosine2 (float xx)
{
	return sine(xx + 1.57);
}

//works from -PI to PI
/*
float nickSIN (float xx)
{
    //https://web.archive.org/web/20171228230531/http://forum.devmaster.net/t/fast-and-accurate-sine-cosine/9648
    #define ABS(N) ((N<0)?(-N):(N))

    const float Beta = 1.273;
	//const float B = 4/pi;	1.273

    const float Gamma = -0.405;  //-0.405
	//const float C = -4/(pi*pi);

    return Beta * xx + Gamma * xx * ABS(xx);
}

float nickCOS (float xx)
{
    return nickSIN(xx + ((xx > 1.57) ? - 4.71 : 1.57));
	//return nickSIN(xx + 1.57);
	//return nickSIN(xx + ((xx > 3.14) ? - 6.28 : 3.14));
}
*/

float _sins (float xx)
{
    #define ABS(N) ((N<0)?(-N):(N))
    const float P = 0.225;
    const float A = 7.589;//16 * sqrt(P);
    const float B = 1.633;//(1 - P) / sqrt(P);
    //float yy = xx / (6.28);
    float yy = xx * .157;

    yy = yy - floor(yy + 0.5);  // y in range -0.5..0.5
    yy = A * yy * (0.5 - ABS(yy));
    return yy * (B + ABS(yy));
}

float _coss (float xx)
{
    return _sins(xx + 1.57);
}

float _sine_hacker(float xx)
{//Dan_Ritchie
	const float B = 1.2734;   //  = 4/PI;
	const float C = -.4057;   //-4/(PI*PI);
	const float recip2 = 0.1592;    //1 / (PI * 2);
	const float pi2 = 6.28;     //PI * 2;
	//float yy;

	//convert the input value to a range of 0 to 1
	xx = (xx + PI) * recip2;
	//make it loop
	xx -= (char)(xx-(xx<0));
	//xx -= (long)(xx-(xx<0));

	//convert back from 0-1 to -pi to +pi.
	xx = (xx * pi2) - PI;

	//original function
	//yy = B * xx + C * xx * ABS(xx);
	//return (yy);

	return B * xx + C * xx * ABS(xx);
}
float _Csine_hacker(float xx)
{
    return _sine_hacker(xx + 1.57);
}

void rtunes_pixelRoutine (void)
{
    //zx_cls(PAPER_WHITE | INK_BLACK);
    for (yy = 0; yy < 192; yy++)
    {
        for (xx = 0; xx < 255 ; xx++)
        {
            gfx_xy = (yy << 8) | xx;
            rtunes_pixel();
        }
    }
}

void rtunes_plot(unsigned char x, unsigned char y)
{
    if (x > 254)
        x = 254;
    if (y > 190)
        y = 190;



    gfx_xy = (y << 8) | x;
    rtunes_pixel();

}

void plot(unsigned char x, unsigned char y)
{
    *zx_pxy2saddr(x,y) |= zx_px2bitmask(x);
}

void draw_circle ()
{
    int x1, y1;
    int length = 50;
    float angle = 0.0;
    float angle_stepsize = 0.01;
    const unsigned int SCREEN_W = 256;
    const unsigned int SCREEN_H = 192;
    unsigned char HALF_W = SCREEN_W / 2;
    unsigned char HALF_H = SCREEN_H / 2;

    // go through all angles from 0 to 2 * PI radians
    while (angle < 2 * PI)
    {
        // calculate x1, y1 from a vector with known length and angle
        x1 = length * cos (angle);
        y1 = length * sin (angle);

        rtunes_plot (x1 + HALF_W, y1 + HALF_H);
        angle += angle_stepsize;
    }
}

void draw_line ()
{
    int x1, y1;
    int x2, y2;
    int length = 50;
    int start = 0;

    float angle = 0.0;
    float angle_stepsize = 0.01;
    const unsigned int SCREEN_W = 256;
    const unsigned int SCREEN_H = 192;
    unsigned char HALF_W = SCREEN_W / 2;
    unsigned char HALF_H = SCREEN_H / 2;

    x1 = HALF_W;
    y1 = HALF_H;

    while (start < length)
    {
        // calculate x1, y1 from a vector with known length and angle
        x2 = x1 + length * cos (angle);
        y2 = y1 + length * sin (angle);

        rtunes_plot (x2 + HALF_W, y2 + HALF_H);
        angle += angle_stepsize;
        start ++;
    }
}


void SIN_COS_line (unsigned char X, unsigned char Y, unsigned char length, float angle)
{
    unsigned endX, endY;
    unsigned char startX = X;
    unsigned char startY = Y;
    unsigned char counter = 0;
    length = 50;

    while (counter < length)
    {
        endX = startX + 2 * sin(angle);
        endY = startY + 2 * cos(angle);

        rtunes_plot(endX, endY);
        length ++;
    }
}


void gameLine (void)
{
    float radian = 0.0;
    float step = -1.0;
    int x1 = 128;
    int y1 = 96;
    int x2 = 0;
    int y2 = 0;
    int loop1 = 0;
    int angle = 0;

    for (angle = 0; angle < 360; angle++)
    {
        x1 = 128;
        y1 = 96;
        for (loop1 = 0; loop1 < 30; loop1++)
        {
            radian = degree2radian (angle);
            //Ball_sprite_X += step * sin (radian);
            //Ball_sprite_Y += step * cos (radian);
            x2 = x1 + loop1 * cos (radian);
            y2 = y1 + loop1 * sin (radian);


            rtunes_plot(x2, y2);

            printf("\x16\x01\x02");
            printf ("radian = %f", radian);
            printf ("X1 = %d    Y1 = %d     \n", x1, y1);
            printf ("X2 = %d    Y2 = %d     \n", x2, y2);
            printf ("step = %d     \n", step);
            printf ("loop1 = %d   angle = %d    \n", loop1, angle);
        }

        x1 = 128;
        y1 = 96;
    }
}






void bresenham_angle(unsigned char x1, unsigned char y1, unsigned char length, float angle)
{
    int dy;
    int dx;
    int stepx;
    int stepy;
    int fraction = 0;
    float cos2;
    float sin2;

    int x2;
    int y2;


//_sine_hacker    _Csine_hacker
    //good takes 32 seconds but in range
    //from 0 to 6.28
    cos2 = _Csine_hacker(angle);//cosine
    sin2 = _sine_hacker(angle);




    //good routines from -PI to PI
    {
        //z88dk ver     takes approx 48 seconds
        //cos2 = cos(angle);//cosine
        //sin2 = sin(angle);

		//nickSIN nickCOS
		//works from -PI to PI
        //close, perhaps range reduction
        //cos2 = nickCOS(angle);
        //sin2 = nickSIN(angle);



		//z88dk ver     takes approx 50 seconds
        //cos2 = cosf(angle);//cosine
        //sin2 = sinf(angle);


        //cos2 = _mikeCOS(angle);
        //sin2 = _mikeSIN(angle);

        //funky shape like triangle
        //cos2 = _oneCoderCOS(angle);
        //sin2 = _oneCoderSIN(angle);

        //hand coded ver takes approx 30 seconds
        //cos2 = cosine2(angle);//cosine
        //sin2 = sine(angle);

        //hand coded ver takes approx 28 seconds
        //close, but does't close completely
        //cos2 = _cos_Smile(angle);
        //sin2 = _sin_Smile(angle);
    }
    {//odd routines
        //oval with shrinking edge
        //cos2 = fastCOS6(angle);
        //sin2 = fastSIN6(angle);

        //myFastSin   myFastCos
        //cos2 = myFastCos(angle);
        //sin2 = myFastSin(angle);

        //cos2 = _coss(angle);//cosine
        //sin2 = _sins(angle);

		//fast_sine   fast_cosine
		//cos2 = fast_cosine(angle);//cosine
		//sin2 = fast_sine(angle);

    }

    {//non working routines
        //hand coded ver takes approx  seconds
        //embeddedSIN embeddedCOS
        //NOPE  horizontal lines, must be out of range
        //cos2 = embeddedCOS(angle);
        //sin2 = embeddedSIN(angle);

        //buggy //NOPE  horizontal lines, must be out of range
        //cos2 = fast_cos7(angle);
        //sin2 = fast_sin7(angle);

        //javaSIN     javaCOS
        //cos2 = javaCOS(angle);
        //sin2 = javaSIN(angle);

        //javaSIN2    javaCOS2
        //cos2 = javaCOS2(angle);//cosine
        //sin2 = javaSIN2(angle);

        //quad_sin    quad_cos
        //cos2 = quad_cos(angle);
        //sin2 = quad_sin(angle);

        //cos2 = _cosin2(angle);//cosine
        //sin2 = _sin2(angle);


        //cos2 = _cosinner(angle);//cosine
        //sin2 = _sinner(angle);
    }






    //printf ("A=%.2f \n",bob);
    //printf ("sin= %.3f cos= %.3f \n", sin2, cos2);


    //fastCOS
    //double x2 = x1 + (length * cos(radians));
    //double y2 = y1 + (length * sin(radians));
    x2 = x1 + ((float)length * cos2);
    y2 = y1 + ((float)length * sin2);

    dy = y2 - y1;
    dx = x2 - x1;

    if (dy < 0)
    {
        dy = -dy;
        stepy = -1;
    }
    else
    {
        stepy = 1;
    }

    if (dx < 0)
    {
        dx = -dx;
        stepx = -1;
    }
    else
    {
        stepx = 1;
    }

    dy <<= 1;        // dy is now 2*dy
    dx <<= 1;        // dx is now 2*dx

	rtunes_plot(x1,y1);//plot(x1,y1);

    if (dx > dy)
    {
        fraction = dy - (dx >> 1);	// same as 2*dy - dx
        while (x1 != x2)
        {
            if (fraction >= 0)
            {
                y1 += stepy;
                fraction -= dx;	// same as fraction -= 2*dx
            }
            x1 += stepx;
            fraction += dy;	// same as fraction -= 2*dy

            rtunes_plot(x1,y1);
            dummyWait ();
        }
    }
    else
    {
        fraction = dx - (dy >> 1);
        while (y1 != y2)
        {
            if (fraction >= 0)
            {
                x1 += stepx;
                fraction -= dy;
            }
            y1 += stepy;
            fraction += dx;

            rtunes_plot(x1,y1);
            dummyWait ();
        }
    }


}



void bresenham_line(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2)
{
    int dy = y2 - y1;
    int dx = x2 - x1;
    int stepx;
    int stepy;
    int fraction = 0;

    if (dy < 0)
    {
        dy = -dy;
        stepy = -1;
    }
    else
    {
        stepy = 1;
    }

    if (dx < 0)
    {
        dx = -dx;
        stepx = -1;
    }
    else
    {
        stepx = 1;
    }

    dy <<= 1;        // dy is now 2*dy
    dx <<= 1;        // dx is now 2*dx

	rtunes_plot(x1,y1);//plot(x1,y1);

    if (dx > dy)
    {
        fraction = dy - (dx >> 1);	// same as 2*dy - dx
        while (x1 != x2)
        {
            if (fraction >= 0)
            {
                y1 += stepy;
                fraction -= dx;	// same as fraction -= 2*dx
            }
            x1 += stepx;
            fraction += dy;	// same as fraction -= 2*dy

            rtunes_plot(x1,y1);

        }
    }
    else
    {
        fraction = dx - (dy >> 1);
        while (y1 != y2)
        {
            if (fraction >= 0)
            {
                x1 += stepx;
                fraction -= dy;
            }
            y1 += stepy;
            fraction += dx;

            rtunes_plot(x1,y1);
        }
    }
}

#endif
