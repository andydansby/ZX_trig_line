// using sdcc_iy 1.99c

#pragma printf = %f


//Using advise from Stefan
//moved Stack pointer from $BFFF to $C000 as
//Stack automatically decrements before useage
// see zpragma.inc in Uncontended

#define ABS(N) ((N<0)?(-N):(N))
#define PI 3.14
// edit to add conversion
    #define radian2degree(a) (a * 57.295779513082)
    #define degree2radian(a) (a * 0.017453292519)


#include <arch/zx.h>
#include <stdio.h>//standard input output
#include <input.h>//used for detecting key inputs
#include <math.h>


#include <intrinsic.h>//temp to place labels
//powerful troubleshooting tool
        //intrinsic_label(border_start);
        //intrinsic_label(border_end);

#include "externs.h"    //references to asm functions
#include "variables.h"

#include "uncontended.h"
#include "functions.h"






void main ()
{
    //new
    SETUP_IM2();// set up for the interrupt MODE 2
    // this will point the I register to IM2 Vector

    zx_cls(PAPER_WHITE);

	printf ("Hello Angles\n");

    xorshift_prng ();//generate a Pseudo Random number
    random_number_16 = random_number_16 % (255 + 1 - 0) + 0;
    //printf("\x16\x01\x02");
    //printf ("random number =  %d \n", random_number_16);
    //printf ("\n");

    //printf ("01234567890123456789012345678901\n");

    printf ("enter rad :");
    //fgets(input, 100, stdin);
    //scanf(input, "%f ", &floatInput);
    //printf ("\n floatInput = %f \n", floatInput);

    //printf ("enter length :");
    //scanf ("%d", length);
    //printf ("\n Line length = %d \n", length);


    {//using Z88dk built in functions
        //x_coordinate = 128;
        //y_coordinate = 47;
        //plot(x_coordinate, y_coordinate);
    }
    {
        //x_coordinate = 128;
        //y_coordinate = 47;
        //rtunes_plot(x_coordinate, y_coordinate);
        //rtunes_pixelRoutine();
    }

/*
    temp1 = 0;
    //628 entries in an array at .01 steps

    {
        //radians = 1.047;
        radians = floatInput;
        radian2degree ();

        printf ("floatInput = %f \n", floatInput);
        printf ("degrees= %d\n", degrees);
    }
	radians = 4.712;
	printf ("radians = %f \n", radians);
	*/


/*
    //with sine
    //bresenham_angle(128, 96, 50, -3.14);// line left slightly up
    //bresenham_angle(128, 96, 50, -1.57);// line up
    //bresenham_angle(128, 96, 50, 0);// line right
    //bresenham_angle(128, 96, 50, 1.57);// line down
    //bresenham_angle(128, 96, 50, 3.14);// line down

    //with _mikeSIN
    //bresenham_angle(128, 96, 50, -3.14);// line left slightly up
    //bresenham_angle(128, 96, 50, -1.57);// line up
    //bresenham_angle(128, 96, 50, 0);// line right
    //bresenham_angle(128, 96, 50, 1.57);// line down
    //bresenham_angle(128, 96, 50, 3.14);// line down
*/
	//with sine
	// bresenham_angle(128, 96, 50, radians);

	//straight down

	//SIN_COS_line (128, 96, 20, .222);
    //draw_circle ();
    //draw_line();
    gameLine();





    /*for (bob = -3.14; bob < 3.14; bob=bob + .01)
    {
        bresenham_angle(128, 96, 50, bob);
        //temp1++;
    }*/

    /*for (bob = 0; bob < 6.28; bob=bob + .01)
    {
        bresenham_angle(128, 96, 50, bob);
    }*/

    //printf ("temp1 =  %u \n", temp1);

    /*for (bob = -1; bob < 1; bob=bob + .01)
    {
        bresenham_angle(128, 96, 50, bob);
    }*/

/*
    for (bob = 0; bob < 3.14; bob=bob + .01)
    {
        bresenham_angle(128, 96, 50, bob);
    }*/

    /*for (bob = -1.57; bob < 3.14; bob=bob + .01)
    {
        bresenham_angle(128, 96, 50, bob);
    }*/

    /*
    for (bob = -1.57; bob < 1.57; bob=bob + .01)
    {
        bresenham_angle(128, 96, 50, bob);
    }

    */


    /*for (bob = -3.16; bob < 3.16; bob=bob + .01)
    {
        bresenham_angle(128, 96, 50, bob);
    }*/



    /*for (bob = 0; bob < 1; bob=bob + .01)
    {
        bresenham_angle(128, 96, 50, bob);
    }*/
    /*for (temp5 = 0; temp5 < 420; temp5++)
    {
        bob = (0.1*temp5)/32768;

        //@420 .1*420 = 42

        //sin1(0.1*i)/32768




        bresenham_angle(50, 90, 25, bob);
    }*/




    //bresenham_angle(128, 96, 70, 3.1415);



    //bresenham_angle(50, 90, 25, 1);
    //bresenham_angle(50, 90, 25, 2);



    /*for (temp5 = 0; temp5 < 360; temp5++)
    {
        //bob = (float)temp / 360;
        bresenham_angle(50, 90, 25, temp5);
    }*/

    //setup
    //ball.speed = 5 + random.randint(0, 7)
    //ball.dir = 4 + ((random.randint(0, 10)/10)-0.5)

    //ball.x += ball.speed * math.sin(ball.dir)
    //ball.y += ball.speed * math.cos(ball.dir)

    //d = math.degrees(ball.dir)%360
    //inc = -1.5
    //if d > 90 and d < 270:        //going up
    //    inc = 1.5
    //    ball.speed -= 0.03
    //    if ball.speed < 0: ball.dir = 0
    //else:
    //    if ball.speed < 10: ball.speed += 0.04


    //bresenham_angle(50, 90, 25, 90);
    //bresenham_angle(50, 90, 25, 270);

    /*for (bob = -3.14; bob < 3.14; bob = bob + .01)
    {
        bresenham_angle(128, 96, 50, bob);
    }*/




    printf ("finish");


    while (1)
    {
    }
}

// must have blank line at end
