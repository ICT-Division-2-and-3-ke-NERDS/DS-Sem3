#include <stdio.h>
void swap(int *a,int *b){
    printf("Student Name: Ronit Kundnani");
    printf("Student RollNo: 24BIT100");
    int temp=*a;
    *a=*b;
    *b=temp;

}
int main(){
    int a=10,b=20;
    swap(&a,&b);
    printf("swapped values: a:%d b:%d",a,b);
    return 0;
}