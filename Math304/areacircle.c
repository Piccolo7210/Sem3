#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define EPS 10.0e-6
#define H(x) (sqrt(x)-(x*x))
double bisection(double a,double b){
	int n=100,i;
	double first=a,last=b,c;
	if(H(first)*H(last)>0) {
	printf("No root.\n");
	exit(0);
}
	for(i=1;i<n;i++)
	{
		c=(first+last)/2;
		if(fabs(H(c))<EPS){
			break;
		}
		if(H(first)*H(c)<0)last=c;
		else first=c;
	}
return c;
}
double Trape(double a,double b,int n){
	int i;
	double sum_x,sum_I,I,h;	
	h=(b-a)/n;
	double x[n+1],y[n+1];
	x[0]=a;
	for( i=1;i<n;i++)
	{
		x[i]=x[i-1]+h;
	}
	x[n]=b;
	y[0]=H(x[0]);
	for(int i=1;i<n;i++)
	{
		y[i]=H(x[i]);
	}
	y[n]=H(x[n]);
	sum_x=y[0]+y[n];
	sum_I=0;
	for(i=1;i<n;i++)sum_I+=y[i];
	I=(sum_x+2*sum_I)*(h/2);
	return I;
	
}
int main(){
	double l=0.5,r=1.25,a;
	a=bisection(l,r);
	printf("Crossing point = %lf\n",a);
	int n;
	printf("Enter the N = ");
	scanf("%d",&n);
	double area;
	area=Trape(0,a,n);
	printf("Area = %lf",fabs(area));
}
