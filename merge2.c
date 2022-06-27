#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* llist_input(int len);
Node* find_mid(Node* head);
Node* divide(Node* head);
Node* merge(Node* l1, Node* l2);
Node* print_llist(Node* head);

int main(){
    int len;
    scanf("%d", &len);
    Node* head = llist_input(len);

    head = divide(head);
    print_llist(head);
}

Node* print_llist(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* p = temp;
        printf("%d ", temp->data);
        temp = temp->next;
        free(p);
    }
}

Node* llist_input(int len){
    
    Node* head = (Node*)malloc(sizeof(Node));
    int n;
    scanf("%d", &n);
    head->data = n;
    head->next = NULL;
    Node* curr = head;

    for(int i = 0; i < len-1; i++){
        Node* temp = (Node*)malloc(sizeof(Node));
        scanf("%d", &n);
        temp->data = n;
        temp->next = NULL;
        curr->next = temp;
        curr = temp;
    }

    return head;

}

Node* find_mid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* divide(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* mid = find_mid(head);
    Node* first = head;
    Node* second = mid->next;
    mid->next = NULL;

    first = divide(first);
    second = divide(second);

    Node* sorted = merge(first, second);
    return sorted;
}

Node* merge(Node* l1, Node* l2){

    if(l1 == NULL){
        return l2;
    }
    if(l2 == NULL){
        return l1;
    }

    Node* answer = (Node*)malloc(sizeof(Node));
    Node* temp = answer;

    Node* head1 = l1;
    Node* head2 = l2;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        }
        else{
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
    }

    while(head1 != NULL){
        temp->next = head1;
        temp = head1;
        head1 = head1->next;
    }

    while(head2 != NULL){
        temp->next = head2;
        temp = head2;
        head2 = head2->next;
    }
    
    return answer->next;
}