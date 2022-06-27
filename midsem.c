#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&n);
    }
    int count=0;
    int i=0;
    int j=1;
    for(int k=0;k<n-1;k++){
        if(arr[j]>arr[i] && j-i==1){
            j++;
            i++;
        }
        else if(arr[j]<arr[i]){
            count++;
            j++; 
        }
        else if(arr[j]>arr[i] && j-i>1){
            i=j;
            j++;
        }
    }
    printf("%d",count);
    
    // int j=0;
    // for(int i=0;i<n;i++){
    //     if(arr[i]>arr[j]){
    //         count++;
    //     }
    //     j++;
    // }
    // for(int i=0;i<n;i++){
    //     if(arr[i]==count){
    //         printf("%d",arr[i]);
    //     }

    // }
    













    return 0;
}
