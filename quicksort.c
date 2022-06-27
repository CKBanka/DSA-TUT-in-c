#include<stdio.h>
void swap(int* a ,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int ar[],int l,int u){
    int p=ar[u];
    int i=l-1;
    for(int j=l;j<u;j++){
        if(ar[j]<p){
            i++;
            swap(&ar[i],&ar[j]);
        }
    }
    swap(&ar[i+1],&ar[u]);
    return i+1;
}
void quicksort(int ar[],int l,int u){
    if(l<u){
        int p=partition(ar,l,u);
        quicksort(ar,l,p-1);
        quicksort(ar,p+1,u);
    }
}
int main(){
    int n;
    int ar[n];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }
    quicksort(ar,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d",ar[i]);
    }
    return 0;
}