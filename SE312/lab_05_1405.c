#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp;
	int line=1,single=0;
	char str[10000],a;
	if((fp=fopen("re.txt","r")) ==NULL){
		printf("Error on Opening.\n");	
		exit(1);
	}
	int i=0;
	while(!feof(fp))
	{
	    a=fgetc(fp);
	    if(a=='\n')line++;
		if(a=='/')
		{
			a=fgetc(fp);
			if(a=='/')
			{
				a=fgetc(fp);
				while(a!='\n')
				{
					str[i++]=a;
					a=fgetc(fp);	
				}
				single=1;
				str[i]='\0';
			}
			else if(a=='*')
			{
				a=fgetc(fp);
				if(a=='\n')line++;
				while(a!='*'){
					str[i++]=a;
					a=fgetc(fp);				
				}
				str[i]='\0';
				fgetc(fp);			
			}		
		}
		if(i!=0 && str[i]=='\0')
		{
			printf("%d: ",line);
			for(i=0;str[i];i++)
			{
				printf("%c",str[i]);						
			}
			printf("\n");
			i=0;
			if(single==1){
			line++;
			single=0;		
			}
			continue;	
		}
	}
fclose(fp);

}
