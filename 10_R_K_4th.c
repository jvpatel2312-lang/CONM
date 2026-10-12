#include<stdio.h>
#include<conio.h>

float f (float x0 , float y0)
{
	return ( x0 + y0);
}

void main()
{
	float x0,y0,h,xn,k1,k2,k3,k4,x,y;
	int i,n;
	clrscr();

	printf("\nEnter Initial X0 : ");
	scanf("%f", &x0);

	printf("\nEnter Initial Y0 : ");
	scanf("%f", &y0);

	printf("\nEnter step size h : ");
	scanf("%f", &h);

	printf("\nEnter Final value xn : ");
	scanf("%f", &xn);

	n = (xn-x0)/h;

	x=x0;
	y=y0;

	printf("\nX\t\t Y\n");
	printf("%.4f\t\t %.4f\n",x,y);

	for(i=1;i<=n;i++)
	{
		k1 = h * f(x,y);

		k2 = h * f(x + h/2 , y + k1/2);

		k3 = h * f(x + h/2 , y + k2/2);

		k4 = h * f(x + h , y + k3);

		y = y + (k1 + (2*k2) + (2*k3) + k4)/6;

		x = x + h;

		printf("%.4f\t\t %.4f\n",x,y);

	}

	printf("\nApprox Solution at X = %.4f is Y = %.4f", xn,y);

	getch();
}