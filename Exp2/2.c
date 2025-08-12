#include <stdio.h>
#include <string.h>
struct Student{
        char name[10];
        int rollno;
        char address[20];
};
int main(){
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");
    struct Student s1;
    struct Student *ptr;
    ptr=&s1;

    strcpy(ptr->name,"ronit");
    ptr->rollno=10;
    strcpy(ptr->address,"BlahBlah");

    printf("name:%s\n",ptr->name);
    printf("rollno:%d\n",ptr->rollno);
    printf("address:%s\n",ptr->address);
    return 0;
}