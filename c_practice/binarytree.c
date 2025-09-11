#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;

}node;


node* insert(node* root,int value){
    if(root==NULL){
node* newnode=(node*)malloc(sizeof(node));
newnode->data=value;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}
if(value<root->data)
root->left=insert(root->left,value);

else
root->right=insert(root->right,value);
return root;
}















void inorder( node* root){
   if(root){

   inorder(root->left);
   
    printf("%d ",root->data);

    inorder(root->right);
}}

void preorder(node* root){
   if(root){

   printf("%d ",root->data);
    inorder(root->left);
    inorder(root->right);
}}

void postorder(node* root){
  
  
    if(root){

   
    inorder(root->left);
    inorder(root->right);
    printf("%d ",root->data);
}}





int main()
{
     node* root=NULL;
     node* temp=NULL;

int n,i,s;
printf("koyta node banaite chao");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("data dao bhai:");
scanf("%d",&s);
root=insert(root,s);
}
preorder(root);


}





