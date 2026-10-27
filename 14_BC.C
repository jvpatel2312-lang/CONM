#include<stdio.h>
#include<conio.h>
#include<math.h>
#define e 0.001
#define f(x)  x*x-3;

void main()
{
    float x0,x1,x2;
    float f0,f1,f2;
    int i = 0;
    clrscr();

    printf("enter value of x0 amd x1:");
    scanf("%f %f",&x0,&x1);

    f0 = f(x0);
    f1 = f(x1);

    if((f0<0 && f1<0) || (f0>0 && f1>0))
    {
	printf("invalid root");
    }

    else
    {
	do{
	    x2=(x0+x1)/2;
	    f2=f(x2);

	    if(f0 *f2 <0)
	    {
		x1=x2;
		f1=f2;
	    }
	    else
	    {
		x0=x2;
		f0=f2;
	     }

	    i++;
	    printf("number of iteration %d",i);
	    printf("root = %f",x2);
	    printf("value of function %f\n",f2);
	}while(fabs(f2)>e);
    }


getch();
}
