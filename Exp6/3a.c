#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *rear = NULL;
struct Node *front = NULL;

int isEmpty()
{
    return (front == NULL);
}

void enqueue(int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    if (front == NULL)
    {
        front = new;
        rear = new;
        new->next = front;
    }
    else
    {
        rear->next = new;
        rear = new;
        rear->next = front;
    }
    printf("Enqueued: %d\n", data);
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow!\n");
        return;
    }
    struct Node *temp = front;
    int val = temp->data;

    if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }
    free(temp);
    printf("Dequeued: %d\n", val);
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue elements:\n");
    do
    {
        printf("Data: %d\n", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(50);
    display();

    return 0;
}
