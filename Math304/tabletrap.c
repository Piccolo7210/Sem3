#include<stdio.h>
int main(){
	double x[11]={0.0,0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0};
	double y[11]={1.0,1.04,1.16,1.36,1.64,2.0,2.44,2.96,3.56,4.24,5.0};
	double sum_x,sum_I=0,I,h;
	int n=10,i;
	h=(x[n]-x[0])/n;
	sum_x=y[0]+y[n];
	for(i=1;i<n;i++)sum_I+=y[i];
	I=(h*(sum_x+2*sum_I))/2;
	printf("Integral value = %lf\n",I);

}
