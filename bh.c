#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct mh{
    int* ar;
    int size;
    int capacity;
}mh;
void swap(int* a,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}
void insert(mh* h,int key){
    if(h->size==h->capacity){
        printf("oberflow\n");
        return;
    }
    int i=h->size;
    h->ar[i]=key;
    h->size++;
    while(i>=0 && h->ar[(i-1)/2]>key){
        swap(&h->ar[(i-1)/2],&h->ar[i]);
        i=(i-1)/2;
    }
}
void decKey(mh* h,int key,int i){
    h->ar[i]=key;
    while(i!=0 && h->ar[(i-1)/2]>h->ar[i]){
        swap(&h->ar[(i-1)/2],&h->ar[i]);
        i=(i-1)/2;
    }
}
// void heapify(mh* h,int i){
//     int l=i*2+1;
//     int r=2*i+2;
//     int c=i;
//     if(l<h->size && h->ar[i]<h->ar[l]){
//         c=l;
//     }
//     if(r<h->size && h->ar[c]<h->ar[r]){
//         c=r;
//     }
//     if(i!=c){
//         swap(&h->ar[c],&h->ar[i]);
//         heapify(h,c);
//     }
// }
void heapify(mh* h, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < h->size && h->ar[l] < h->ar[smallest])
      smallest = l;
    if (r < h->size && h->ar[r] < h->ar[smallest])
      smallest = r;
    if (smallest != i)
    {
      swap(&h->ar[i], &h->ar[smallest]);
      heapify(h, smallest);
  }
}
int extractMin(mh* h){
    if(h->size<1){
        return INT_MAX;
    }
    else if(h->size==1){
        h->size--;
        return h->ar[h->size];
    }
    else{
        int t=h->ar[0];
        h->ar[0]=h->ar[h->size-1];
        h->size--;
        heapify(h,0);
        return t;
    }
}
int getMin(mh* h){
    if(h->size>0){
        return h->ar[0];
    }
    return INT_MIN;
}
void delete(mh* h,int i){
    decKey(h,INT_MIN,i);
    extractMin(h);

}
int main(){
    mh* h=(mh*)malloc(sizeof(mh));
    int c;
    scanf("%d",&c);
    h->size=0;
    h->capacity=c;
    h->ar=(int*)malloc(sizeof(int)*c);
    insert(h,3);
    insert(h,2);
    delete(h,1);
    insert(h,15);
    insert(h,5);
    insert(h,4);
    insert(h,45);
    // for(int i=0;i<6;i++){
    //     printf("%d ",h->ar[i]);
    // }
    printf("%d\n",extractMin(h));
    // for(int i=0;i<6;i++){
    //     printf("%d ",h->ar[i]);
    // }
    printf("%d\n",getMin(h));
    decKey(h,1,2);
    printf("%d\n",getMin(h));
    return 0;

}
