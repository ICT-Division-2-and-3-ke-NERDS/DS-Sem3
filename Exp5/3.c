#include <stdio.h>
#include <stdlib.h>

struct Deque {
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Deque *dq) {
    if (dq->rear==dq->size)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct Deque *dq) {
    return dq->front == -1;
}

void insertFront(struct Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is Full\n");
        return;
    }

    if (dq->front == -1) {  
        dq->front = dq->rear = 0;
    }
    else if (dq->front == 0) { 
        dq->front = dq->size - 1;
    }
    else {
        dq->front--;
    }
    dq->arr[dq->front] = value;
    printf("Inserted %d at front\n", value);
}

void insertLast(struct Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is Full\n");
        return;
    }

    if (dq->front == -1) {  
        dq->front = dq->rear = 0;
    }
    else if (dq->rear == dq->size - 1) { 
        dq->rear = 0;
    }
    else {
        dq->rear++;
    }
    dq->arr[dq->rear] = value;
    printf("Inserted %d at rear\n", value);
}

void deleteFront(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is Empty\n");
        return;
    }

    int value = dq->arr[dq->front];
    printf("Deleted %d from front\n", value);

    if (dq->front == dq->rear) { 
        dq->front = dq->rear = -1;
    }
    else if (dq->front == dq->size - 1) {
        dq->front = 0;
    }
    else {
        dq->front++;
    }
}

void deleteLast(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is Empty\n");
        return;
    }

    int value = dq->arr[dq->rear];
    printf("Deleted %d from rear\n", value);

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    }
    else if (dq->rear == 0) {
        dq->rear = dq->size - 1;
    }
    else {
        dq->rear--;
    }
}

int front(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is Empty\n");
        return -1;
    }
    return dq->arr[dq->front];
}

int rear(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is Empty\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

int main() {
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");

    struct Deque *dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->size = 100;
    dq->front = dq->rear = -1;
    dq->arr = (int*)malloc(dq->size * sizeof(int));

    insertLast(dq, 10);
    insertLast(dq, 20);
    insertFront(dq, 5);
    insertLast(dq, 30);
    printf("Front: %d, Rear: %d\n", front(dq), rear(dq));
    deleteFront(dq);
    deleteLast(dq);
    printf("Front: %d, Rear: %d\n", front(dq), rear(dq));
    return 0;
}
