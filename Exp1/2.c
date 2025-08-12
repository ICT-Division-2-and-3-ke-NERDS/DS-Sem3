#include <stdio.h>
struct Student{
        char name[10];
        int rollno;
        char address[20];
};
int main(){
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");
    int n;
    printf("Enter the number of students:");
    scanf("%d",&n);

    struct Student s1[n];
    for(int i=0;i<n;i++){
        printf("Enter The details of the %d th student \n",(i+1));
        printf("Enter student name:");
        scanf("%s",&s1[i].name);
        printf("Enter student RollNo:");
        scanf("%d",&s1[i].rollno);
        printf("Enter student address:");
        scanf("%s",&s1[i].address);
        printf("\n");
    }
    printf("\n \n");
    for(int i=0;i<n;i++){
        printf("Student %d :\n",i+1);
        printf("student name: %s\n",s1[i].name);
        printf("student RollNo:%d\n",s1[i].rollno);
        printf("student address:%s\n",s1[i].address);
    }

    return 0;
}