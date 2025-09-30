#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct Node *insert(struct Node *root, int val)
{
    if (root == NULL)
    {
        return createNode(val);
    }
    struct Node *current = root;
    while (current != NULL)
    {
        if (val < current->data)
        {
            if (current->left == NULL)
            {
                current->left = createNode(val);
                return root;
            }
            current = current->left;
        }
        else if (val > current->data)
        {
            if (current->right == NULL)
            {
                current->right = createNode(val);
                return root;
            }
            current = current->right;
        }
        else
        {
            return root;
        }
    }
}

void inorder(struct Node *root)
{
    struct Node *stack[100];
    int top = -1;
    struct Node *current = root;
    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d\t", current->data);
        current = current->right;
    }
}

void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    struct Node *stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1)
    {
        struct Node *current = stack[top--];
        printf("%d\t", current->data);

        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

void postorder(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1) {
        struct Node* current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL)
            stack1[++top1] = current->left;
        if (current->right != NULL)
            stack1[++top1] = current->right;
    }

    while (top2 != -1) {
        printf("%d\t", stack2[top2--]->data);
    }
}

int countNodes(struct Node* root) {
    if (root == NULL) return 0;

    int count = 0;
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        struct Node* current = stack[top--];
        count++;
        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }
    return count;
}

int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;

    int count = 0;
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        struct Node* current = stack[top--];
        if (current->left == NULL && current->right == NULL)
            count++;
        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }
    return count;
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");
    struct Node *root = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    insert(root, 2);
    printf("InOrder Traversal:  ");
    inorder(root);
    printf("\n");
    printf("preOrder Traversal:  ");
    preorder(root);
    printf("\n");
    
    printf("postOrder Traversal:  ");
    postorder(root);
    printf("\n");
}