#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *s) {
    return s->top == -1;
}

int isFull(struct stack *s) {
    return s->top == s->size - 1;
}

char pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("stack underflow\n");
        return 0;
    }
    return s->arr[s->top--];
}

char push(struct stack *s, char value) {
    if (isFull(s)) {
        printf("stack overflow\n");
        return -1;
    }
    s->arr[++s->top] = value;
    return value;
}

char top(struct stack *s) {
    if (isEmpty(s)) return '\0';
    return s->arr[s->top];
}

int isOperator(char a) {
    return (a == '+' || a == '-' || a == '*' || a == '/');
}

int precedence(char a) {
    if (a == '*' || a == '/')
        return 3;
    else if (a == '+' || a == '-')
        return 2;
    else if (a == '(')
        return 1; // lowest precedence
    else
        return 0;
}

char *inftopost(char *infix) {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (infix[i] == '(') {
            push(sp, infix[i]);
            i++;
        }
        else if (infix[i] == ')') {
            while (!isEmpty(sp) && top(sp) != '(') {
                postfix[j++] = pop(sp);
            }
            pop(sp); // remove '('
            i++;
        }
        else if (!isOperator(infix[i])) {
            postfix[j++] = infix[i++];
        }
        else {
            while (!isEmpty(sp) && precedence(top(sp)) >= precedence(infix[i])) {
                postfix[j++] = pop(sp);
            }
            push(sp, infix[i]);
            i++;
        }
    }

    while (!isEmpty(sp)) {
        postfix[j++] = pop(sp);
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");
    char *infix = "a+b+c";
    printf("%s\n", inftopost(infix));
    return 0;
}