#include<stdio.h>
#include<stdlib.h>
#define null NULL
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* insertB(Node* start,int n){
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
Node* insertLast(Node* start,int n){
    Node* temp=(Node*)malloc(sizeof(Node));
    Node* temp2=start;
    temp->data=n;
    temp->next=null;
    if(start==null){
        start=temp;
        return start;
    }
    while(temp2->next!=null){
        temp2=temp2->next;
    }
    temp2->next=temp;
    return start;
}
// inseert after m
Node* insert(Node* start,int n,int m ){
    Node* temp=(Node*)malloc(sizeof(Node));
    Node* temp2=start;
    temp->data=n;
    temp->next=null;
    if(start==null){
        start=temp;
        return start;
    }
    while(temp2!=null && temp2->data!=m){
        temp2=temp2->next;
    }
    if(temp2!=null){
        temp->next=temp2->next;
        temp2->next=temp;
    }
    return start;
}

void display(Node* start){
    Node* temp=start;
    while(temp!=null){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}
void delete(Node* start, int n){
    Node* curr=start;
    Node* prev=null;
    if(start==null){
        return;
    }
    if(start->data==n){
        start=start->next;
    }
    else{
        while(curr!=null && curr->data!=n){
            prev=curr;
            curr=curr->next;
        }
        if(curr!=null)
            prev->next=curr->next;
    }
    free(curr);
}
Node* merge(Node* start,Node* mid){
    Node* temp2=start;
    Node* temp1=mid;
    int flag=1;
    Node* start2=(Node*)malloc(sizeof(Node));
    Node* temp3=start2;
    while(temp2!=null && temp1!=null){
        // printf("%d  %d\n", temp1->data,temp2->data);
        if(temp2->data<temp1->data){
            start2->next=temp2;
            start2=temp2;
            temp2=temp2->next;
        }
        else{
            start2->next=temp1;
            start2=temp1;
            temp1=temp1->next;
        }
    }
    
    while(temp2!=null){
        start2->next=temp2;
        start2=temp2;
        temp2=temp2->next;
        

    }
    while(temp1!=null){
        start2->next=temp1;
        start2=temp1;
        temp1=temp1->next;
        
    }
    return temp3->next;
}
void mergesort(Node* start){
    if(start==null || start->next==null){
        return;
    }
    Node* curr=start;
    Node* prev=start;
    while(curr!=null){
        curr=curr->next;
        if(curr!=null){
            prev=prev->next;
            curr=curr->next;
        }
    }
    curr=prev->next;
    prev->next=null;
    mergesort(start);
    mergesort(curr);
    start=merge(start,curr);

}
int main(){
    Node* start=null;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        start=insertB(start,i);
    }
    Node* start1=null;
    int n1;
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        start1=insertB(start1,n1-i);
    }
    // display(merge(start,start1));
    // insertLast(start,10);
    // insertLast(start,5);
    // insertLast(start,99);
    // insertLast(start,0);
    // insertLast(start,10);
    // insert(start,20,2);
    // delete(start,1);
    mergesort(start);
    display(start);
    return 0;
}