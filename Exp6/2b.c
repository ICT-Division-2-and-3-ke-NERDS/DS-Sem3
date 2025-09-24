#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void enqueue(struct Node** front,struct Node** rear,int val){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    if(new==NULL)
    {
        printf("Queue overflow\n");
    }
    else{
        new->data=val;
        new->next=NULL;
        if (*rear==NULL)
        {
            *front=new;
            *rear=new;
        }
        else
        {
            (*rear)->next=new;
            *rear=new;
        }
        printf("value:%d enqued\n",new->data);
    }
}

void dequeue(struct Node** front,struct Node** rear){
    if (*front==NULL)
    {
        printf("Queue underflown\n");
    }
    else{
        struct Node* temp=*front;
        *front=(*front)->next;
        if (*front==NULL)
        {
            *rear=NULL;
        }
        printf("Value:%d dequed\n",temp->data);
        free(temp);
    }
}

void peek(struct Node *front)
{
    if (front == NULL)
    {
        printf("Queue underflown\n");
    }
    else
    {
        printf("%d is the front element\n",front->data);
    }
}

void display(struct Node *front)
{
    if (front == NULL)
    {
        printf("Queue underflown\n");
    }
    else
    {
        struct Node *temp = front;
        printf("Queue elements:");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    struct Node* front=NULL;
    struct Node* rear=NULL;
    enqueue(&front,&rear,10);
    enqueue(&front,&rear,20);
    enqueue(&front,&rear,30);
    enqueue(&front,&rear,40);
    enqueue(&front,&rear,50);
    display(front);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    display(front);
    peek(front);
    return 0;
}