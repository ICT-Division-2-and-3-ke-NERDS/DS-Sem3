#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *s)
{
    return s->top == -1;
}

int isFull(struct stack *s)
{
    return s->top == s->size - 1;
}

char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("stack underflow\n");
        return 0;
    }
    else
    {
        return s->arr[s->top--];
    }
}

char push(struct stack *s, char value)
{
    if (isFull(s))
    {
        printf("stack overflow\n");
        return -1;
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
        return value;
    }
}

char top(struct stack *s)
{
    return s->arr[s->top];
}

int isOperator(char a)
{
    if (a == '+' || a == '-' || a == '/' || a == '*')
        return 1;
    else
        return 0;
}

int precedence(char a)
{
    if (a == '*' || a == '/')
        return 3;
    else if (a == '+' || a == '-')
        return 2;
    else
        return 0;
}

char *inftopost(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // infix traversal
    int j = 0; // postfix traversal
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(top(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a+b+c";
    printf("%s\n", inftopost(infix));
    return 0;
}