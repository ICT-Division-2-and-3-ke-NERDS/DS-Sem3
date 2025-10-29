#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Data: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertAtEnd(struct Node *ptr, int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;

    if (ptr == NULL)
    {
        return new;
    }

    struct Node *p = ptr;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = new;
    return ptr;
}

struct Node *mergeSortedLists(struct Node *a, struct Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    struct Node *result = NULL;

    if (a->data <= b->data)
    {
        result = a;
        result->next = mergeSortedLists(a->next, b);
    }
    else
    {
        result = b;
        result->next = mergeSortedLists(a, b->next);
    }

    return result;
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");

    struct Node *A = NULL;
    struct Node *B = NULL;
    struct Node *merged = NULL;

    //5 -> 10 -> 15
    A = insertAtEnd(A, 5);
    A = insertAtEnd(A, 10);
    A = insertAtEnd(A, 15);

    //2 -> 3 -> 20
    B = insertAtEnd(B, 2);
    B = insertAtEnd(B, 3);
    B = insertAtEnd(B, 20);

    printf("List A:\n");
    traversal(A);

    printf("\nList B:\n");
    traversal(B);

    merged = mergeSortedLists(A, B);

    printf("\nMerged Sorted List:\n");
    traversal(merged);

    return 0;
}
