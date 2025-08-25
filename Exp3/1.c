#include<stdio.h>
#define MAX 20

struct stack{
    int s[MAX];
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

void push(int ele){
    if(isFull()){
       printf("You can't push an element\n");
    }else{
        s1.top += 1;
            s1.s[s1.top]=ele;
            printf("%d is pushed into stack\n", ele);
    }
}

void pop(){
    if(isEmpty()){
       printf("You can't pop an element\n");
    }else{
        printf("%d is popped from the stack\n" ,s1.s[s1.top]);
        s1.top -= 1;
    }
}

void Top(){
    printf("Top element of stack is %d\n" ,s1.s[s1.top]);

}

int main(){
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");
    s1.top = -1;
push(1);
push(3);
push(5);
pop();
push(2);
push(4);
pop();
pop();
Top();
pop();
pop();
pop();
    return 0;
}
