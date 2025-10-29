#include <stdio.h>

int binarySearch(int arr[10],int size,int x){
    int st=0;
    int mid=(size-1)/2;
    int end=size-1;

    while (st<end){
        if (x==arr[mid]){
            printf("Value found at %d\n",mid);
            return mid;
        }else if (x<arr[mid]){
            printf("1");
            end=mid;
            mid=(end-st)/2;    
        }else{
            printf("2");
            st=mid;
            mid=st+(end-st)/2;
        }
    }
    return -1;
}

int main(){
    int arr[10]={10,20,30,40,50,69,70,80,96};
    int x;
    printf("Enter the value you want to find:");
    scanf("%d",&x);
    printf("%d",binarySearch(arr,10,x));
    return 0;
}