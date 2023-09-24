#include<stdio.h>
#define F(x) (x*x+1)
int main(){
	double a,b,h,sum_x,I,sum_O,sum_E,result;
	int n,i;
	scanf("%lf %lf %d",&a,&b,&n);
	if(n%2!=0)n=n+1;
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
	sum_O=0;
	for(i=1;i<n;i+=2)sum_O+=y[i];
	sum_E=0;
	for(i=2;i<n-1;i+=2)sum_E+=y[i];
	I=(h*(sum_x+4*sum_O+2*sum_E))/3;
	printf("Trapezoidal Rule:\n");
	printf("Integral value : %lf",I);
	
	
}
