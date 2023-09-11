#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void strgenerator(char *a);
int length(char a[][11],int num);
int check(char *a);
int stringlen(char *a);
void concat(char *new,char *a,char*b);
int palindrome(char *a);
void set(int k);
int main(){
    int max,len,num,j,i;
    char str[5][11];
     for(i=0;i<5;i++){
        max=rand()% 10 + 1;
        for( j=0;j<max-1;j++){
            num=rand()%2;
            str[i][j]=num+'0';
        }
        str[i][j]='\0';
    }
	printf("Five Generated String and their length :\n");
    for(int i=0;i<5;i++){
    printf("%s   ",str[i]);
    printf("%d",length(str,i));
    printf("\n");
    }
	printf("*****From alphabet or Not from Alphabet check:*****\n");
    char w[11];
    int flag;
    printf("Enter W: ");
    scanf("%s",w);
    flag=check(w);
    if(flag== 1)printf("From Alphabet\n");
    else printf("Not from Alphabet\n");
    char x[11];
    strgenerator(x);
    char y[11];
    strgenerator(y);
    printf("Concatanation part:\n");
    printf("x: %s\n",x);
    printf("y: %s\n",y);
    int size;
    size=stringlen(x)+stringlen(y)+1;
    char new[size];
    concat(new,x,y);
    printf("New string: %s\n",new);
    
    /*
       ======== PALINDROME===========
    */
    printf("===== PALINDROME====\n");
    char m[11];
    scanf("%s",m);
    palindrome(m);
	printf("********SET CHECK*********\n");
	int k;	
	printf("Enter the number K: ");
	scanf("%d",&k);
	set(k);
    return 0;
}





int length(char a[][11],int num){
    int count=0;
    for(int i=0;a[num][i]!='\0';i++)count++;
    return count;
}
void strgenerator(char *a){
    int j,max,num;
    max=rand()% 10 + 1;
        for( j=0;j<max-1;j++){
            num=rand()%2;
            a[j]=num+'0';
        }
        a[j]='\0';
}
int check(char *a){
    int  flag;
    flag=1;
    for(int i=0;a[i];i++){
        if(a[i]!='0' && a[i]!='1')
        {
            flag=0;
            break;
        }
    }
    return flag;
}
int stringlen(char *a){
    int count=0;
    for(int i=0;a[i];i++)count++;
    return count;
}
void concat(char *new,char *a,char*b){
    int i=0,j=0;
    while(a[i]){
        new[i]=a[i];
        i++;
    }
    while(b[j]){
        new[i]=b[j];
        j++;
        i++;
    }
    new[i]='\0';
}
int palindrome(char *a){
    printf("String M = %s\n",a);
    int len,flag=1; 
    len=stringlen(a);
    printf("length = %d\n",len);
        for(int i=0;i<len/2;i++){
            if(a[i]==a[len-1-i])continue;
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==1)printf("Palindrome\n");
        else printf("Not Palindrome\n");
}
void set(int k){
	int i,j,n;
	n=pow(2,k);
	char arr[n][k+1];
	for(i=0;i<n;i++){
		int a=i;
		for(j=0;j<k;j++){
			arr[i][j]=a%2+'0';
			a=a/2;	
		}
		arr[i][j]='\0';	
	}
	printf("Elements: ");
	printf("{ ");
	for(i=0;i<n;i++){		
		for(j=k-1;j>=0;j--){
			printf("%c",arr[i][j]);		
		}
		if(i!=n-1)printf(",");	
	}
	printf(" }");
}
