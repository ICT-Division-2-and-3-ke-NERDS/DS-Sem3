#include<stdio.h>
#include<string.h>
#define MAX 20

struct stack{
    char s[MAX];
    int top;
};

struct stack s1;

int isEmpty(){
    if(s1.top == -1){
        printf("Stack is Empty or Underflow\n");
        return 1;
    }
    return 0;
}

int isFull(){
    if(s1.top == MAX-1){
        printf("Stack is Full or Overflow\n");
        return 1;
    }
    return 0;
}

void push(char ele){
    if(isFull()){
       printf("You can't push an element\n");
    }else{
        s1.top += 1;
            s1.s[s1.top]=ele;
            //printf("%c is pushed into stack\n", ele);
    }
}

char pop(){
    if(isEmpty()){
       printf("You can't pop an element\n");
    }else{
        char popped = s1.s[s1.top];
        //printf("%c is popped from the stack\n" ,s1.s[s1.top]);
        s1.top -= 1;
        return popped;
    }
}

void Top(){
    printf("Top element of stack is %c\n" ,s1.s[s1.top]);

}

int main(){
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");
    s1.top = -1;
    int i;
    char A[MAX];
    gets(A);
    for(i=0;i<=strlen(A);i++){
        push(A[i]);
    }
    printf("Reverse of String :\n");
    for(i=0;i<=strlen(A);i++){
        printf("%c",pop());
    }
    return 0;
}
