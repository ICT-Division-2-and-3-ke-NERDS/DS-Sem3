#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int size;
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

int isOperant(char a)
{
    return (a >= '0' && a <= '9');
}

int inftopost(char *exp)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 100;
    s->arr = (char *)malloc(s->size * sizeof(char));
    int i = 0;
    while (exp[i] != '\0')
    {
        if (isOperant(exp[i]))
        {
            push(s, exp[i]);
        }
        else
        {
            if (exp[i] == '+')
            {
                int second = pop(s) - '0';
                int first = pop(s) - '0';
                char c = first + second + '0';
                push(s, c);
            }
            else if (exp[i] == '-')
            {
                int second = pop(s) - '0';
                int first = pop(s) - '0';
                char c = first - second + '0';
                push(s, c);
            }
            else if (exp[i] == '*')
            {
                int second = pop(s) - '0';
                int first = pop(s) - '0';
                char c = first * second + '0';
                push(s, c);
            }
            else if (exp[i] == '/')
            {
                int second = pop(s) - '0';
                int first = pop(s) - '0';
                char c = first / second + '0';
                push(s, c);
            }
        }
        i++;
    }

    return pop(s) - '0';
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");
    char * exp="23+54*+";
    // char *exp = "22/";
    printf("Result:%d", inftopost(exp));
    return 0;
}