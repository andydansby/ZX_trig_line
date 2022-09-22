
//not working
/*
float _cosin2 (float xx)
{
    //#define ABS(N) ((N<0)?(-N):(N))
	const float tp = 0.159;     // == 1 / (2*M_PI);
	xx *= tp;
	xx -= .25 + floor(xx + .5);
	xx *= 16 * (ABS(xx) - (.25));
	return xx;
}

float _sin2 (float xx)
{
	return _cosin2(xx - 1.57);
}
*/
///////////////////////////////////////////
/*
float fast_sin7(float x)
{
    return 4.0 * (0.318 * x * (1.0 - ABS(0.318 * x)));
}
float fast_cos7(float x)
{
   return 4.0 * (0.5 - 0.318 * x) * (1.0 - ABS(0.5 - 0.318 * x));
}
*/
///////////////////////////////////////////
//nope
/*
float quad_sin (float xx)
{
    const float alpha = -0.417;
    const float beta = 1.312;
    const float gamma = 0.050;
    float powX = xx * xx;
    return alpha * powX + beta * xx - gamma;
}
float quad_cos (float xx)
{
    return quad_sin(xx + 1.57);
}
*/
///////////////////////////////////////////
/*
float _sinner (float xx)
{
	const float A = -0.417698;
	const float B = 1.312236;
	const float C = 0.050465;
	float temp = 0;
	float D = xx * xx;

	return (A * D) + (B * xx) - C;
}
float _cosinner (float xx)
{
	return _sinner(xx - 1.57);
}
*/
///////////////////////////////////////////

//java sine
//http://www.java2s.com/example/java/java.lang/fast-cosine-approximation.html
/*
float javaSIN (float xx)
{
    const float Alpha = -0.4056;
    const float Beta = 1.2738;
    const float Gamma = 2.25;
    float xxx;
    xxx = Beta * xx + Alpha * xx * ABS (xx);
    return Gamma * (xxx * ABS (xxx) - xxx) + xxx;
}

float javaCOS (float xx)
{
    return javaSIN(xx + 1.57);
    //return javaSIN(xx + ((xx > 1.57) ? - 4.71 : 1.57));
}

float javaSIN2 (float xx)
{
    const float Alpha = -0.4057;    //-0.4056;
    const float Beta = 1.2734;      //1.2738
    const float Gamma = 0.1592;       //2.25
    float xxx;
    xxx = Beta * xx + Alpha * xx * ABS (xx);
    return Gamma * (xxx * ABS (xxx) - xxx) + xxx;
}

float javaCOS2 (float xx)
{
    return javaSIN(xx + 1.57);
    //return javaSIN(xx + ((xx > 1.57) ? - 4.71 : 1.57));
}
*/

//range 0 to PI/2 (1.57)
/*
float embeddedCOS (float xx)
{
    const float c1 = 0.999;    //0.99940307
    const float c2 = -0.496;    //0.49558072
    const float c3 = 0.037;    //0.03679168
    float x2 = xx*xx;

    return (c1 + x2*(c2+c3 * x2));
}

float embeddedSIN (float xx)
{
    return embeddedCOS(1.57 - xx);
}
*/

///////////////////////////////
//range [-pi,pi]
//-1 to 1  no, but close to range
//-PI to PI, very wrong
//0 to 6.28 starts ok but fails after
//0 to 3.14 starts ok but fails after
/*
float fast_sine(float xx)
{
    const float alpha = 0.318;
    float xxx = 4.0 * (alpha * xx * (1.0f - alpha * xx));
    return xxx;
}

//range [-pi,pi]
float fast_cosine(float xx)
{
    const float alpha = 0.318;
    float xxx = 4.0 * (0.5 - alpha * xx) * (1.0 - ABS(0.5 - alpha * xx));
    return xxx;
}
*/
///////////////////////////////
/*
float fastSIN6 (float xx)
{
    //return 1.2732395f * x + -0.636619772f * x * fabs(x);
    //return 1.27323954 * x - 0.405284735 * x * fabs(x);
    //return 1.273 * x - 0.405 * x * ABS(x);
    return 1.273 * xx - 0.405 * xx * fabs(xx);
}

float fastCOS6 (float xx)
{
    return fastSIN6(.628 - xx);
}
*/

/*
float bhaskaraSin(float xx)
{
	//https://stackoverflow.com/questions/18662261/fastest-implementation-of-sine-cosine-and-square-root-in-c-doesnt-need-to-b/62425331#62425331
    //float alpha = xx
	xx /= DOUBLEPI;		//2 * PI = 6.28
	xx -= (int)xx;

	if (xx <=.5)
	{
		t = 2 * xx * (2 * xx - 1);
		return (PI * t) / ((-.86) * t - 1);//PI - 4 = -.86
	}
	else
	{
		t = 2 * (1 - xx) * (1 - 2 * xx);
		return -(PI * t) / ((-.86) * t - 1);//PI - 4 = -.86
	}
}
*/
