#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int x;
    struct node *left,*right;
}node;
int swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    return 0;
}
int sort(int *arr,int begin,int end){
    int min=arr[0],i,j;
    for(i=begin;i<=end;i++){
        for(j=i+1;j<=end;j++){
            if(arr[j]<arr[i])
            swap(&arr[i],&arr[j]);
        }
    }
    return 0;
}
node* create_node(int x){
    node *n1 = (node*)malloc(sizeof(node));
    if(n1==NULL)
    exit(1);
    n1->x=x;
    n1->left=NULL;
    n1->right=NULL;
}
int preorder(node *root){
    if(root==NULL)
    return 0;
    else{
        printf("%d ",root->x);
        preorder(root->left);
        preorder(root->right);
    }
}
int postorder(node *root){
    if(root==NULL)
    return 0;
    else{
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->x);
    }
}
int inorder(node *root){
    if(root==NULL)
    return 0;
    else{
        inorder(root->left);
        printf("%d ",root->x);
        inorder(root->right);
    }
}
int add_node(node* n1,node* root){
    if(root==NULL)
    return 0;
    else{
        node *temp=root;
        if(n1->x<=temp->x){
            if(temp->left==NULL){
                temp->left=n1;
                return 0;
            }
            else{
                add_node(n1,root->left);
            }
        }
        else if(n1->x>temp->x){
            if(temp->right==NULL){
                temp->right=n1;
                return 0;
            }
            else{
                add_node(n1,root->right);
            }
        }
    }
    return 0;
}
int input(int *arr){
    int i=0;
    char ch;
    int temp=0;
    while(1){
    ch=getchar();
    if(ch==-1)
        break;
    else if(ch==','||ch==' ')
        continue;
    else{
        temp=ch-'0';
        while(1){
            ch=getchar();
            if(ch==-1)
            break;
            else if(ch==',')
            break;
            else{
                temp = temp * 10 + (ch-'0');
            }
        }
        arr[i++]=temp;
    }
    }
    return i;
}
int main(){
    int arr[100],i;
    int n=input(arr);
    sort(arr,0,n-1);
    node *head;
    head = create_node(arr[n/2]);
    for(int i=1;i<n/2;i++){
        add_node(create_node(arr[i]),head);
    }
    for(int i=n/2+1;i<n;i++){
        add_node(create_node(arr[i]),head);
    }
    printf("Array: %d elements\n",n);
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\nBinary Search Tree:\n");
    printf("inorder:");
    inorder(head);
    printf("\n");
    printf("preorder:");
    preorder(head);
    printf("\n");
    printf("postorder:");
    postorder(head);
    return 0;
}
