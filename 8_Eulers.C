#include<stdio.h>
#include<conio.h>
#include<math.h>

float f(float x, float y)
{
	return (y-x)/(y+x);
}

void main()
{
	float x0,y0,xn,h,x1,y1;
	int i=0,n;
	clrscr();

	printf("\nEnter x0,y0,h,xn : ");
	scanf("%f %f %f %f", &x0,&y0,&h,&xn);
	// x0=0 y0=1 h=0.02 xn=0.1

	//Number of steps
	n= (xn-x0)/h;

	// n=(0.1-0)/0.02
	//  =0.1/0.02
	//  =5

	printf("\n======EULER METHOD=====\n");
	printf("i\t x\t y\n");
	printf("%d\t %.4f\t %.4f\n",i,x0,y0);

	// i  x   y
	// 0  0   1

	for(i=1;i<=n;i++)
	{
		// Eular Formula
		// define f(x,y) = ((y-x) / (y+x))


		y1 = y0 + h * f(x0,y0);

		// Iteration i = 1

		// f(x0,y0) = (1-0)/(1+0) = 1

		// ==> y1 = 1+0.02*1 = 1+0.02 = 1.0200

		// Interation i = 2

		// f(x0,y0) = (1.02-0.02)/(1.02+0.02) = 1 / 1.04 = 0.9615

		// ==> y1 = 1.0200 + 0.02 * 0.9615 = 1.0200 + 0.01923 = 1.0392



		x1 = x0 + h;

		// x1 = 0   +0.02 = 0.02
		// x1 = 0.02+0.02 = 0.04
		// x1 = 0.04+0.02 = 0.06
		// x1 = 0.06+0.02 = 0.08
		// x1 = 0.08+0.02 = 0.10


		printf("%d\t %.4f\t %.4f\n", i,x1,y1);

		// x=0.02 , y=1.02
		// x=0.04 , y=1.0392
		// x=0.06 , y=1.0577
		// x=0.08 , y=1.0756
		// x=0.10 , y=1.0929


		x0=x1;

		// x0=0.2000
		// x0=0.4000
		// x0=0.6000
		// x0=0.8000
		// x0=0.1000

		y0=y1;

		// y0=1.0200
		// y0=1.0392
		// y0=1.0577
		// y0=1.0756
		// y0=1.0929

	}

	printf("\nFinal value at x=%.4f if Y=%.4f", x1,y1);

	getch();

}