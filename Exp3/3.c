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
            
    }
}

char pop(){
    if(isEmpty()){
       printf("You can't pop an element\n");
    }else{
        char popped = s1.s[s1.top];
        
        s1.top -= 1;
        return popped;
    }
}

void Top(){
    printf("Top element of stack is %c\n" ,s1.s[s1.top]);

}

int isValid(char* s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (isEmpty()) return 0; 
            char top = pop();
            if ((s[i] == ')' && top != '(') ||
                (s[i] == '}' && top != '{') ||
                (s[i] == ']' && top != '[')) {
                return 0; 
            }
        }
    }
    return isEmpty(); 
}



int main(){
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");
    s1.top = -1;
    
    char A[MAX];
    printf("Enter a string of parentheses: ");
    fgets(A, MAX, stdin);
    A[strcspn(A, "\n")] = 0; 
    if (isValid(A)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is invalid.\n");
    }
    Top();
    return 0;
}
