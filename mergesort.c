#include<stdio.h>
void merge(int ar[],int l,int r,int m){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++){
        L[i]=ar[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=ar[m+i+1];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            ar[l++]=L[i++];
        }
        else{
            ar[l++]=R[j++];
        }
    }
    while(i<n1){
        ar[l++]=L[i++];
    }
    while(j<n2){
        ar[l++]=R[j++];
    }
}
void mergeSort(int ar[],int l, int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(ar,l,m);
        mergeSort(ar,m+1,r);
        merge(ar,l,r,m);
    }
}
int main(){
    int n;
    int ar[n];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }
    mergeSort(ar,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d",ar[i]);
    }
    return 0;
}