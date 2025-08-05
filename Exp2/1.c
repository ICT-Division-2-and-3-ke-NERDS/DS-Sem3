#include <stdio.h>
int main(){
    printf("Student Name: Ronit Kundnani");
    printf("Student RollNo: 24BIT100");
    int a=10,b=20,c=30;
    int *ptr[]={&a,&b,&c};
    for(int i=0;i<3;i++){
        printf("%d\n",ptr[i]);
    }

    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int *p=arr;
    for(int i=0;i<10;i++){
        printf("%d\n",*(p+i));
    }
    return 0;
}