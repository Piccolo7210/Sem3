#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10.0e-6
#define F(x) (x*x*x+4*x*x-10)
void falsepos(double a,double b){
	int n=100,i;
	double first=a,last=b,c;
	if(F(first)*F(last)>0) exit(0);
	 					    printf("===============================================================================================================================\n");
	printf("  Iter	       \'first\'		 \'last\'		     \'c\'	        \'F(first)\'		\'F(last)\'	    \'F(c)\'\n");
	printf("===============================================================================================================================\n");
	for(i=1;i<n;i++)
	{
		c=((F(last)*first)-(b*F(first)))/(F(last)-F(first));
		printf("%d	      %lf		%lf	    %lf	       %lf	   	%lf	    %lf\n",i,first,last,c,F(first),F(last),F(c));
		
		if(fabs(F(c))<EPS){
			printf("Root=%lf\n",c);
			exit(0);
		}
		if(F(first)*F(c)<0)last=c;
		else first=c;
	}
}
int main(){
	double a,b;
	printf("Enter two endpoint : ");
	scanf("%lf %lf",&a,&b);
	falsepos(a,b);
	return 0;
}
