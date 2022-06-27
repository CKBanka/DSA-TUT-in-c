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
int search(bst* root,int key){
    if(root==null){
        return 0;
    }
    else if( root->data==key){
        return 1;
    }
    else if(root->data>key){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
// int successor(bst* root){
//     int max=
//     if(root->right!=null){
        
//     }
// }
bst* insert(bst* root, int n){
    if(root==null){
        bst* temp=(bst*)malloc(sizeof(bst));
        temp->data=n;
        temp->left=temp->right=null;
        root=temp;
    }
    else{
            if(root->data < n){
                root->right=insert(root->right,n);
            }
            else{
                root->left=insert(root->left,n);
            }
        
    }
    return root;
}
bst* newN(int n){
    bst* temp=(bst*)malloc(sizeof(bst));
    temp->data=n;
    temp->right=temp->left=null;
}

void printIn(bst* root){
    if(root==null){
        return;
    } 
    printIn(root->left);
    printf("%d ",root->data);
    printIn(root->right);
}
void printPre(bst* root){
    if(root==null){
        return;
    } 
    printf("%d",root->data);
    printPre(root->left);
    printPre(root->right);
}
void printPost(bst* root){
    if(root==null){
        return;
    } 
    printPost(root->left);
    printPost(root->right);
    printf("%d",root->data);
}
int max(int a,int b){
    return (a>b)?a:b;
}
int hieght(bst* root){
    if(root!=null){
        return 1+max(hieght(root->right),hieght(root->left));
    }
    return 0;
}
int count(bst* root){
    if(root!=null){
        return 1+ count(root->right)+count(root->left);
    }
    return 0;
}
bst* successor(bst* root){
    bst* curr=root->right;
    while(curr!=null && curr->left!=null){
        curr=curr->left;
    }
    return curr;
}
bst* delete(bst* root,int key){
    if(root==null){
        return root;
    }
    else if(root->data>key){
        root->left=delete(root->left,key);
    }
    else if(root->data<key){
        root->right=delete(root->right,key);
    }
    else{
        if(root->right==null){
            bst* temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==null){
            bst* temp=root->right;
            free(root);
            return temp;
        }
        else{
                bst* temp=successor(root);
                root->data=temp->data;
                root->right= delete(root->right,temp->data);
        }
    }
    return root;
}
int main(){
    bst* root= null;
    int n;
    scanf("%d",&n);
    int d;
    for(int i =0;i<n;i++){
        scanf("%d",&d);
        root=insert(root,d);
    }

    printIn(root);
    printf("\n");

    int key;
    scanf("%d",&key);

    root=delete(root,key);

    printIn(root);
    printf("\n");

    // printf("%d",hieght(root));

    return 0;
}