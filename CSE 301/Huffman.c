#include<stdio.h>
#include<stdlib.h>
#define n 6
struct node{
	char c;
	int freq;
	struct node *right;
	struct node *left;	
};
struct node* huffman_tree(struct node *arr[]);
struct node* create_node(int freq);
void print(struct node* tree, int *arr, int ind);
void sort(struct node* arr[]);
int main(){
	struct node *arr[n];
    int huffcode[n];
	for(int i=0;i<n;i++)arr[i]=malloc(sizeof(struct node));
	for(int i=0;i<n;i++){
		arr[i]->right=NULL;
		arr[i]->left=NULL;
		scanf("%c %d",&arr[i]->c,&arr[i]->freq);
		getchar();
	}
	struct node *tree;
    tree=huffman_tree(arr);
    print(tree,huffcode,0);
}
void sort(struct node* arr[]){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
				if(arr[i]->freq> arr[j]->freq){
					struct node *new;
					new=malloc(sizeof(struct node));
					new=arr[j];
					arr[j]=arr[i];
					arr[i]=new;
				}
		}
	}
}
struct node* create_node(int freq){
    struct node *new;
    new=malloc(sizeof(struct node));
    new->c='*';
    new->freq=freq;
    new->right=NULL;
    new->left=NULL;
    return new;
}
struct node* huffman_tree(struct node *arr[]){
    
    int max=5000;
    for(int i=1;i<=n-1;i++){
        int freq;
        sort(arr);
        freq=arr[0]->freq +arr[1]->freq;
        struct node *new;
        new=create_node(freq);
        new->left=arr[0];
        new->right=arr[1];
        arr[0]=new;
        arr[1]->freq=max;
        max++;
    }
    return arr[0];
}
void print(struct node* tree, int *arr, int ind){
    if(tree->left==NULL && tree->right==NULL){
        printf("Character = %c , Code = ",tree->c);
        for(int i=0;i<ind;i++){
            printf("%d",arr[i]);
        }
        printf("\n");
    }
    if(tree->left){
        arr[ind]=0;
        print(tree->left,arr,ind+1);
    }
    if(tree->right){
        arr[ind]=1;
         print(tree->right,arr,ind+1);
    }
   
}
