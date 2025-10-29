#include <stdio.h>

int linearSearch(int arr[10],int x){
    for (int i = 0; i < 10; i++){
        if (arr[i]==x){
            printf("%d found\n");
            return i;
        }
        else
            continue;
    }
    return -1;
}

int main(){
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    int x;
    printf("Enter any Number to search:");
    scanf("%d",&x);
    int index=linearSearch(arr,x);
    if (index==-1){
        printf("Value Not Found\n");
    }
    else{
        printf("Value found at %d",index);
    }
    return 0;
}