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
        return 0;
    }
    return s->arr[s->top--];
}

char push(struct stack *s, char value) {
    if (isFull(s)) {
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
        return 2;
    else if (a == '+' || a == '-')
        return 1;
    else
        return 0;
}

void reverse(char *exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
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
        }
        else if (infix[i] == ')') {
            while (!isEmpty(sp) && top(sp) != '(') {
                postfix[j++] = pop(sp);
            }
            pop(sp); // remove '('
        }
        else if (!isOperator(infix[i])) {
            postfix[j++] = infix[i];
        }
        else {
            while (!isEmpty(sp) && precedence(top(sp)) >= precedence(infix[i])) {
                postfix[j++] = pop(sp);
            }
            push(sp, infix[i]);
        }
        i++;
    }

    while (!isEmpty(sp)) {
        postfix[j++] = pop(sp);
    }
    postfix[j] = '\0';
    free(sp->arr);
    free(sp);
    return postfix;
}

char *inftopre(char *infix) {
    int n = strlen(infix);

    char *rev = (char *)malloc((n + 1) * sizeof(char));
    strcpy(rev, infix);
    reverse(rev);

    // Swap brackets
    for (int i = 0; i < n; i++) {
        if (rev[i] == '(') rev[i] = ')';
        else if (rev[i] == ')') rev[i] = '(';
    }

    char *post = inftopost(rev);

    reverse(post); // reverse postfix to get prefix

    free(rev);
    return post;
}

int main() {
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");

    char exp[] = "a+b+c";

    printf("Result: %s\n", inftopre(exp));
    
    return 0;
}
