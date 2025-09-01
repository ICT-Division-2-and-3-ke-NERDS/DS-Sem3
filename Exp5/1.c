#include <stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue *queue){
    if (queue->rear==queue->size)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

int isEmpty(struct Queue *queue){
    if (queue->front==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

int insertion(struct Queue *queue,int value){
    if (isFull(queue))
    {
        printf("Queue is Full\n");
        return 0;
    }
    else{
        queue->rear++;
        if (queue->front==-1)
        {
            queue->front=0;
        }
        
        queue->arr[queue->rear]=value;
        return value;
    }
    
}

int deletion(struct Queue *queue){
    if (isEmpty(queue))
    {
        printf("Queue is Empty\n");
        return 0;
    }
    else{
        int value=queue->arr[queue->rear];
        queue->rear--;
        return value;
    }
}

int front(struct Queue *queue){
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return 0;
    }
    else{
        return queue->arr[queue->front];
    }
}

int rear(struct Queue *queue){
    if (!isEmpty(queue))
    {
        return queue->arr[queue->rear];
    }
    else{
        printf("Queue is empty\n");
        return 0;
    }
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");
    struct Queue *queue=(struct Queue*)malloc(sizeof(struct Queue));
    queue->size=100;
    queue->front=-1;
    queue->rear=-1;
    queue->arr=(int *)malloc(sizeof(int)*queue->size);
    insertion(queue,10);
    printf("Front: %d, Rear: %d\n", front(queue), rear(queue));
    printf("Value inserted %d\n",insertion(queue,20));
    printf("Value inserted %d\n",insertion(queue,40));
    printf("Value inserted %d\n",insertion(queue,39));
    printf("Value inserted %d\n",insertion(queue,30));
    printf("Front: %d, Rear: %d\n", front(queue), rear(queue));
    printf("Value deleted %d\n",deletion(queue));
    printf("Front: %d, Rear: %d\n", front(queue), rear(queue));
    return 0;
}