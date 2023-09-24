#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10.0e-6
#define F(x) (x*x*x+4*x*x-10)
int main(){
	int n=100,i;
	double first=1.25,last=1.5,c;
	if(F(first)*F(last)>0) exit(0);
	 					    printf("===============================================================================================================================\n");
	printf("  Iter	       \'first\'		 \'last\'		     \'c\'	        \'F(first)\'		\'F(last)\'	    \'F(c)\'\n");
	printf("===============================================================================================================================\n");
	for(i=1;i<n;i++)
	{
		c=(first+last)/2;
		printf("%d	      %lf		%lf	    %lf	       %lf	   	%lf	    %lf\n",i,first,last,c,F(first),F(last),F(c));
		
		if(fabs(F(c))<EPS){
			printf("Root=%lf\n",c);
			exit(0);
		}
		if(F(first)*F(c)<0)last=c;
		else first=c;
	}
	return 0;
}
