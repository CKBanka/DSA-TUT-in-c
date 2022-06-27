#include<stdio.h>
#include<stdlib.h>
#define null NULL
typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct queue{
    Node* head;
    Node* tail;
}queue;

void enqueue(queue* q,int n){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=n;
    temp->next=null;
    if(q->tail==null){
        q->head=temp;
        q->tail=temp;
        return;
    }
    q->tail->next=temp;
    q->tail=temp;
}
int dequeue(queue* q){
    if(q->head==null){
        printf("empty queue\n");
        return 0;
    }
    Node* temp=q->head;
    q->head=q->head->next;
    int val=temp->data;
    free(temp);
    if (q->head == null){
        q->tail = null;
    }
    return val;
}

int main(){
    queue* q =(queue*)malloc(sizeof(queue));
    q->head=null;
    q->tail=null;
    enqueue(q,5);
    enqueue(q,1);
    enqueue(q,0);
    enqueue(q,9);
    enqueue(q,55);
    printf("%d",dequeue(q));
    printf("%d",dequeue(q));
    printf("%d",dequeue(q));
    printf("%d",dequeue(q));
    printf("%d",dequeue(q));
    printf("%d",dequeue(q));
    enqueue(q,9);
    enqueue(q,55);
    printf("%d",dequeue(q));
    return 0;

}