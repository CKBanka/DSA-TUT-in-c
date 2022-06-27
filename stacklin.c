#include<stdio.h>
#include<stdlib.h>
#define null NULL
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* top;

Node* push(Node* start,int n){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=n;
    temp->next=null;
    if(start==null){
        start=temp;
        return start;
    }
    temp->next=start;
    start=temp;
    return start;
}
Node* pop(Node* s){
    if(s==null){
        printf("Empty Stack\n");
        return null;
    }
    Node* temp=s;
    int val=s->data;
    s=s->next;
    printf("%d",val);
    return s;
}
void peek(Node* s){
    if(s==null){
        printf("Empty Stack\n");
    }
    printf("%d",s->data);
}
int main(){
    Node* top=null;
    top=push(top,1);
    top=push(top,2);
    top=push(top,4);
    top=push(top,3);
    // s->stack=push(s->stack,2);
    // s->stack=push(s->stack,3);
    // s->stack=push(s->stack,5);
    // s->stack= push(s->stack,7);
    // s->stack=push(s->stack,4);
    peek(top);
    top=pop(top);
    top=pop(top);
    top=pop(top);
    top=pop(top);
    top=pop(top);
    return 0;
}