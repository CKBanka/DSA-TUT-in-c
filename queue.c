#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int* ar;
    int size;
    int  front;
    int rear;
}queue;
void insert(queue* q,int n){
    if(q->rear==q->size){
        printf("overflow\n");
        return;
    }
    q->ar[q->rear++]=n;

}
int pop(queue* q){
    if(q->rear==q->front){
        printf("Empty Queue\n");
        q->rear=q->front=0;
        return 0;
    }
    return q->ar[q->front++];
}
int main(){
    queue* q=(queue*)malloc(sizeof(queue));
    q->size=5;
    q->front=0;
    q->rear=0;
    q->ar=(int*)malloc(sizeof(int)*q->size);
    insert(q,5);
    insert(q,8);
    insert(q,1);
    insert(q,4);
    insert(q,9);
    insert(q,0);
    insert(q,3);
    printf("%d ",pop(q));
    printf("%d ",pop(q));
    printf("%d ",pop(q));
    printf("%d ",pop(q));
    printf("%d ",pop(q));
    printf("%d ",pop(q));
    printf("%d ",pop(q));
    printf("%d ",pop(q));
    insert(q,1);
    insert(q,4);
    insert(q,9);
    insert(q,0);
    insert(q,3);
    printf("%d ",pop(q));
    printf("%d ",pop(q));
    printf("%d ",pop(q));
    printf("%d ",pop(q));
    return 0;
}