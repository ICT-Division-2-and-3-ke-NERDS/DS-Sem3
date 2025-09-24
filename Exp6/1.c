#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

int len(struct Node *ptr)
{
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    return count;
}

void forwardTraversal(struct Node *ptr)
{
    while (ptr!= NULL)
    {
        printf("Data:%d\n", ptr->data);
        ptr = ptr->next;
    }

}

void backwardTraversal(struct Node *ptr){
    while (ptr->next!= NULL)
    {
        ptr = ptr->next;
    }
    while (ptr!=NULL)
    {
        printf("Data:%d\n", ptr->data);
        ptr=ptr->prev;
    } 
}

struct Node *insertAtBeginning(struct Node *ptr, int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->next = ptr;
    new->data = data;
    new->prev = NULL;
    return new;
}

struct Node* insertAtEnd(struct Node *ptr,int data){
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->next=NULL;
    new->data=data;
    struct Node *head=ptr;
    while (head->next!= NULL)
    {
        head = head->next;
    }
    head->next=new;
    new->prev=head;
    return ptr;
}

struct Node *insertAtPosition(struct Node *ptr, int data, int index)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = ptr;
    int i = 0;
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    new->next = p->next;
    new->prev = p;
    p->next = new;
    new->data = data;
    if (new->next != NULL)
    {
        p = new->next;
        p->prev = new;
    }
    return ptr;
}

int search(struct Node *ptr, int value)
{
    int i=0;
    while (ptr!=NULL)
    {
        i++;
        if (ptr->data==value){
            return i;
        }
        else{
            ptr = ptr->next;
        }
    }
    return -1;
}

struct Node *deleteFromBeginning(struct Node *ptr)
{
    struct Node *p = ptr;
    ptr = ptr->next;
    ptr->prev = NULL;
    free(p);
    
    return ptr;
}

struct Node* deleteAtEnd(struct Node *ptr){
    struct Node *head = ptr;
    
    while ((ptr->next)->next!= NULL)
    {
        ptr = ptr->next;
    }
    struct Node *last=ptr->next;
    free(last);
    ptr->next=NULL;
    
    return head;
}

struct Node *deleteFromPosition(struct Node *ptr, int index)
{
    if(len(ptr)<index){
        printf("Invalid index\n");
        return ptr;
    }
    else{
        struct Node *p = ptr;
        struct Node *q = ptr->next;
        for (int i = 1; i < index-1 ; i++)
        {
            printf("yes\n");
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        if (q->next!=NULL)
        {
            (q->next)->prev=p;
        }
        
        
        free(q);
        return ptr;
    }
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    head->prev = NULL;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 99;
    third->prev = second;
    third->next = NULL;
    head=insertAtBeginning(head,0);
    head=insertAtEnd(head,10);
    head=insertAtPosition(head,100,3);
    forwardTraversal(head);
    printf("The index of 99 is %d",search(head,99));
    head=deleteFromBeginning(head);
    head=deleteFromPosition(head,3);
    head=deleteAtEnd(head);
    backwardTraversal(head);
    return 0;
}