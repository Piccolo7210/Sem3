#include<stdio.h>
#define F(x) (x*x+1)
double Trape(double a,double b){
	double a,b,h,sum_x,I,sum_I,result;
	int n,i;
	scanf("%lf %lf %d",&a,&b,&n);
	h=(b-a)/n;
	double x[n+1],y[n+1];
	x[0]=a;
	for( i=1;i<n;i++)
	{
		x[i]=x[i-1]+h;
	}
	x[n]=b;
	y[0]=F(x[0]);
	for(int i=1;i<n;i++)
	{
		y[i]=F(x[i]);
	}
	y[n]=F(x[n]);
	sum_x=y[0]+y[n];
	sum_I=0;
	for(i=1;i<n;i++)sum_I+=y[i];
	
	I=(h*(sum_x+2*sum_I))/2;
	printf("Trapezoidal Rule:\n");
	printf("Integral value : %lf",I);
	
	
}
