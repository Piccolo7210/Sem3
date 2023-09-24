#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10.0e-6
#define F(x) (x*x*x+4*x*x-10)
void secant(double a,double b){
	int n=100,i;
	double first=a,last=b,c;
	 					    printf("===============================================================================================================================\n");
	printf("  Iter	       \'first\'		 \'last\'		     \'c\'	        \'F(first)\'		\'F(last)\'	    \'F(c)\'\n");
	printf("===============================================================================================================================\n");
	for(i=1;i<n;i++)
	{
		c=last-((F(last)*(last-first))/(F(last)-F(first)));
		printf("%d	      %lf		%lf	    %lf	       %lf	   	%6.6lf	    %lf\n",i,first,last,c,F(first),F(last),F(c));
		
		if(fabs(F(c))<EPS){
			printf("Root=%lf\n",c);
			exit(0);
		}
		first=last;
		last=c;
	}
}
int main(){
	double a,b;
	printf("Enter two point : ");
	scanf("%lf %lf",&a,&b);
	secant(a,b);
	return 0;
}
