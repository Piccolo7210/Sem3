#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10.0e-6
#define F(x) (x*x*x+4*x*x-10)
#define DF(x) (3*x*x+8*x)
void newton(double a){
	int n=100,i;
	double x0=a,x1;			    printf("===============================================================================================================================\n");
	printf("  Iter	       \'x0\'		 \'x1\'	        \'F(x0)\'		\'F'(x0)\'	    \'F(x1)\'\n");
	printf("===============================================================================================================================\n");
	for(i=1;i<n;i++)
	{
		x1=x0 -(F(x0)/DF(x0));
		printf("%d	      %lf		%lf	 %lf	 %lf	     %lf\n",i,x0,x1,F(x0),DF(x0),F(x1));
		
		if(fabs(F(x1))<EPS){
			printf("Root=%lf\n",x1);
			exit(0);
		}
		x0=x1;
	}
}
int main(){
	double a;
	printf("Enter initial value : ");
	scanf("%lf",&a);
	newton(a);
	return 0;
}
