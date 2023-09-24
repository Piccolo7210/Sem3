#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10.0e-6
#define F(x) (x*x*x+4*x*x-5)
void bisection(double a,double b){
	int n=100,i;
	double first=a,last=b,c;
	if(F(first)*F(last)>0){ 
		printf(" [%lf,%lf] : NO ROOT\n",a,b);		
		return;
	}
	printf("[%lf,%lf] : Root ",a,b); 
	for(i=1;i<n;i++)
	{
		c=(first+last)/2;
		if(fabs(F(c))<EPS){
			printf("%lf\n",c);
			return;
		}
		if(F(first)*F(c)<0)last=c;
		else first=c;
	}
}
int main(){
	double a,b,h;
	int n=6,i;
	printf("Enter two endpoint : ");
	scanf("%lf %lf",&a,&b);
	h=(b-a)/n;
	printf("Root:\n");
	for(i=0;i<n;i++){
		b=a+h;
		bisection(a,b);
		a=b;
	}
	return 0;
}
