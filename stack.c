#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int* ar;
    int size;
    int top;
}stack;
void push(stack* s,int n){
    if(s->top==s->size){
        printf("Overflow\n");
        return;
    }
    s->ar[s->top++]=n;
}
int pop(stack* s){
    if(s->top==0){
        printf("Empty Stack");
        return 0;
    }
    return s->ar[--s->top];
}
int peek(stack* s){
    if(s->top==0){
        printf("Empty Stack");
        return 0;
    }
    return s->ar[s->top-1];
}
int main(){
    stack* s=(stack*)malloc(sizeof(stack));
    s->size=5;
    s->top=0;
    s->ar=(int*)malloc(sizeof(int)*s->size);
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,5);
    push(s,7);
    push(s,4);
    printf("%d",pop(s));
    printf("%d",peek(s));
    return 0;
}