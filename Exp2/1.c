#include <stdio.h>
int main(){
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");
    int a=10,b=20,c=30;
    int *ptr[]={&a,&b,&c};
    printf("Array Of Pointers\n");
    for(int i=0;i<3;i++){
        printf("%d\n",*ptr[i]);
    }
    printf("Pointers Of Array \n");
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int *p=arr;
    for(int i=0;i<10;i++){
        printf("%d\n",*(p+i));
    }
    return 0;
}