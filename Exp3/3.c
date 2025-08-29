#include <stdio.h>
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

char push(struct stack *s, char value)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
        return 0;
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
        return value;
    }
}

char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflown\n");
        return 0;
    }
    else
    {
        return s->arr[s->top--];
    }
}

int match(char f, char b)
{
    if (f == '{' && b == '}')
    {
        return 1;
    }
    if (f == '[' && b == ']')
    {
        return 1;
    }
    if (f == '(' && b == ')')
    {
        return 1;
    }
    return 0;
}

int parenthesisMatch(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }

            popped_ch = pop(sp);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");

    char *exp = "[(	)]{}{[(	)(	)](	)}";

    if (parenthesisMatch(exp))
    {
        printf("Parenthesis Matching\n");
    }
    else
    {
        printf("Parenthesis not Matching \n");
    }

    return 0;
}