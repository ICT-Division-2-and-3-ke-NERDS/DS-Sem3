#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
};

struct Node *front = NULL;

int isEmpty()
{
    return (front == NULL);
}

void insert(int data, int priority)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->priority = priority;
    new->next = NULL;

    if (isEmpty() || priority < front->priority)
    {
        new->next = front;
        front = new;
    }
    else
    {
        struct Node *temp = front;
        while (temp->next != NULL && temp->next->priority <= priority)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
    printf("Inserted: %d with priority %d\n", data, priority);
}

void delete()
{
    if (isEmpty())
    {
        printf("Priority Queue Underflow!\n");
        return;
    }

    struct Node *temp = front;
    printf("Deleted element: %d with priority %d\n", temp->data, temp->priority);
    front = front->next;
    free(temp);
}

void display()
{
    if (isEmpty())
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    struct Node *temp = front;
    printf("Priority Queue elements:\n");
    while (temp != NULL)
    {
        printf("Data: %d  |  Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");

    insert(10, 3);
    insert(20, 2);
    insert(30, 4);
    insert(40, 1);
    insert(50, 2);

    display();

    delete();
    delete();

    display();

    return 0;
}
