#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void push(struct Node **top, int val)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    if (new == NULL)
    {
        printf("stack overflow\n");
    }
    else
    {
        new->data = val;
        new->next = *top;
        *top = new;
        printf("Element %d pushed successfully\n", new->data);
    }
}

void pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack underflown\n");
    }
    else
    {
        struct Node *temp = *top;
        *top = (*top)->next;
        printf("Element %d popped succesfuly\n", temp->data);
        free(temp);
    }
}

void peek(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack underflown\n");
    }
    else
    {
        printf("%d is the top element\n",top->data);
    }
}

void display(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack underflown\n");
    }
    else
    {
        struct Node *temp = top;
        printf("Stack elements:");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");
    struct Node *top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 40);
    push(&top, 50);
    push(&top, 60);
    display(top);
    pop(&top);
    pop(&top);
    display(top);
    peek(top);
    return 0;
}