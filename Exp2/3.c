#include <stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
int main(){
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");
    int a=10,b=20;
    printf("Values Before swapping a:%d and b:%d\n",a,b);
    swap(&a,&b);
    printf("swapped values: a:%d b:%d",a,b);
    return 0;
}