#include<stdio.h>
#include<stdlib.h>
#define null NULL
#define yes printf("yes")
#define no printf("no")
typedef struct bst{
    int data;
    struct bst* left;
    struct bst* right;
}bst;
int isBst(bst* root){
    static bst* prev=null;
    if(root!=null){
            if(!isBst(root->left)){
                return 0;
            }
            if(prev!=null && root->data<=prev->data){
                return 0;
            }
            prev=root;
            return isBst(root->right);
    }
    else{
        return 1;
    }
}
bst* new(int d){
    bst* temp=(bst*)malloc(sizeof(bst));
    temp->data=d;
    temp->left=temp->right=null;
    return temp;
}
void printPre(bst* root){
    if(root==null){
        return;
    } 
    printf("%d",root->data);
    printPre(root->left);
    printPre(root->right);
}
int main(){
    bst* root=null;
    root=new(3);
    root->left=new(2);
    root->left->left=new(1);
    // root->left->right=new(4);
    root->right=new(5);
    printf("%d",isBst(root));
    return 0;
}