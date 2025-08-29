#include <stdio.h>

struct Queue
{
    int front;
    int rear;
    int arr[100];
};

int isFull(struct Queue *queue){
    if (queue->rear==99)
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
    struct Queue queue;
    queue.front=-1;
    queue.rear=-1;
    insertion(&queue,10);
    printf("%d\n",front(&queue));
    printf("Value inserted %d\n",insertion(&queue,20));
    printf("Value inserted %d\n",insertion(&queue,40));
    printf("Value inserted %d\n",insertion(&queue,39));
    printf("Value inserted %d\n",insertion(&queue,30));
    printf("Value deleted %d\n",deletion(&queue));
    printf("%d\n",front(&queue));
    printf("%d\n",rear(&queue));
    return 0;
}