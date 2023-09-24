#include<stdio.h>
#include<math.h>
#define PI 3.1415926
int main(){
	double a=0,b=2*PI,x;
	int n=100;
	double h=(b-a)/n;
	x=a;
	printf("\"X\",\"X\",\"X+Sin(X)\"\n");
	for(int i=1;i<=n;i++){
		printf("%lf,%lf,%lf\n",x,x,x+sin(x));
		x+=h;	
	}
	printf("%lf,%lf,%lf\n",b,b,b+sin(b));
}
