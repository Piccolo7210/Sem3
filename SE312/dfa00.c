#include<stdio.h>
int main(){
	char str[15],d,path[15];
	scanf("%s",str);
	d='a';
	int i;
	printf("Starting: %c then:\n",d);
	for(i=0;str[i];i++){
	switch(d){
	 case 'a': if(str[i]=='0') d='b';
    		   else d='a';
		   path[i]=d;
   		   break;
   	case 'b': if(str[i]=='0') d='c';
    		  else d='a';
		  path[i]=d;
   		  break;
   	case 'c': if(str[i]=='0') d='c';
    		  else d='a';
		  path[i]=d;
   		  break;	
	}
	
	}
	path[i]='\0';
	printf("Path: %s\n",path);
	if(d=='c')printf("Accepted.\n");
	else printf("Not accepted.\n");
	
}

