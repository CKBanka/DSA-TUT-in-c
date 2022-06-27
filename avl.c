#include<stdio.h>
#include<stdlib.h>
#define null NULL
#define yes printf("yes")
#define no printf("no")
typedef struct avl{
    struct avl* right;
    struct avl* left;
    int  height;
    int data;
} avl;
int max(int a,int b){
    return (a>b)?a:b;
}
int height(avl* root){
    if(root!=null){
        return 1+max(height(root->left),height(root->right));
    }
    return 0;
}
int getBalance(avl* root){
    if(root!=null){
        return height(root->right)-height(root->left);
    }
    return 0;
}
avl* leftRo(avl* root){
    avl* temp=root->right;
    avl* temp2=temp->left;
    temp->left=root;
    root->right=temp2;
    root->height=height(root);
    temp->height=height(temp);
    return temp;

}
avl* rightRo(avl* root){
    avl* temp=root->left;
    avl* temp2=temp->right;
    temp->right=root;
    root->left=temp2;
    root->height=height(root);
    temp->height=height(temp);
    return temp;

}
void preOrder(avl* root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
avl* insert(avl* root,int n){
    if(root==null){
        avl* temp=(avl*)malloc(sizeof(avl));
        temp->data=n;
        temp->right=temp->left=null;
        temp->height=0;
        return temp;
    }
    if(n<root->data){
        root->left=insert(root->left,n);
    }
    else if(n>root->data){
        root->right=insert(root->right,n);
    }
    else{
        return root;
    }
    root->height=height(root);
    int balance=getBalance(root);
    if(balance<-1 && n<root->left->data){
        return rightRo(root);
    }
    if(balance>1 && n>root->right->data){
        return leftRo(root);
    }
    if(balance<-1 && n>root->left->data){
        root->left=leftRo(root->left);
        return rightRo(root);
    }
    if(balance>1 && n<root->right->data){
        root->right=rightRo(root->right);
        return leftRo(root);
    }
    return root;
}
avl* successor(avl* root){
    avl* curr=root->right;
    while(curr!=null && curr->left!=null){
        curr=curr->left;
    }
    return curr;
}
avl* delete(avl* root,int n){
    if(root==null){
        return root;
    }
    else if(n<root->data){
        root->left=delete(root->left,n);
    }
    else if(n>root->data){
        root->right=delete(root->right,n);
    }
    else{
        if(root->right==null){
            avl* temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==null){
            avl* temp=root->right;
            free(root);
            return temp;
        }
        else{
                avl* temp=successor(root);
                root->data=temp->data;
                root->right= delete(root->right,temp->data);
        }
    }
    if(root==null){
        return root;
    }
    root->height=height(root);
    int balance=getBalance(root);
    if(balance<-1 && getBalance(root->left) <= 0){
        return rightRo(root);
    }
    if(balance>1 &&  getBalance(root->right) <= 0){
        return leftRo(root);
    }
    if(balance<-1 &&  getBalance(root->left) > 0){
        root->left=leftRo(root->left);
        return rightRo(root);
    }
    if(balance>1 &&  getBalance(root->right) > 0){
        root->right=rightRo(root->right);
        return leftRo(root);
    }
    return root;

}
void inorder(avl* root){
    if(root!=null){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(avl* root){
    if(root!=null){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);

    }
}
int main(){
    avl* root=null;
    int  n;
    scanf("%d",&n);
    int d;
    for(int i=0;i<n;i++){
        scanf("%d",&d);
        root=insert(root,d);
    }
    preorder(root);
    int key;
    scanf("%d",&key);
    root=delete(root,key);
    preorder(root);
    return 0;
    
}