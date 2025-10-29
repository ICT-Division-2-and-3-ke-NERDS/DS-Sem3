#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty()
{
    return (front == NULL);
}

void insertFront(int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->prev = NULL;
    new->next = front;

    if (isEmpty())
    {
        rear = new;
    }
    else
    {
        front->prev = new;
    }
    front = new;
    printf("Inserted at Front: %d\n", data);
}

void insertRear(int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    new->prev = rear;

    if (isEmpty())
    {
        front = new;
    }
    else
    {
        rear->next = new;
    }
    rear = new;
    printf("Inserted at Rear: %d\n", data);
}

void deleteFront()
{
    if (isEmpty())
    {
        printf("Deque Underflow at Front!\n");
        return;
    }
    struct Node *temp = front;
    int val = temp->data;

    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    else
    {
        front->prev = NULL;
    }
    free(temp);
    printf("Deleted from Front: %d\n", val);
}

void deleteRear()
{
    if (isEmpty())
    {
        printf("Deque Underflow at Rear!\n");
        return;
    }
    struct Node *temp = rear;
    int val = temp->data;

    rear = rear->prev;
    if (rear == NULL)
    {
        front = NULL;
    }
    else
    {
        rear->next = NULL;
    }
    free(temp);
    printf("Deleted from Rear: %d\n", val);
}

void displayForward()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Deque (Front → Rear):\n");
    while (temp != NULL)
    {
        printf("Data: %d\n", temp->data);
        temp = temp->next;
    }
}

void displayBackward()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }
    struct Node *temp = rear;
    printf("Deque (Rear → Front):\n");
    while (temp != NULL)
    {
        printf("Data: %d\n", temp->data);
        temp = temp->prev;
    }
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");

    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(1);

    displayForward();

    deleteFront();
    deleteRear();

    displayBackward();

    insertRear(50);
    displayForward();

    return 0;
}
