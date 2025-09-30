#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    return new;
}

struct Node * insert(struct Node* root,int val){
    if (root==NULL)
    {
        return createNode(val);
    }
    if (root->data>val)
    {
        root->left=insert(root->left,val);
    }
    else if (root->data<val)
    {
        root->right=insert(root->right,val);
    }
    return root;
}

void postorder(struct Node* root){
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
    
}

void preorder(struct Node* root){
    if (root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    
}

void inorder(struct Node* root){
    if (root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
    
}

struct Node* search(struct Node* root, int val) {
    if (root == NULL || root->data == val) {
        return root;  
    }
    if (val < root->data)
        return search(root->left, val);   
    else
        return search(root->right, val);  
}

int findHeight(struct Node* root){
    if (root==NULL)
        return -1;
    int leftHeight=findHeight(root->left);
    int rightHeight=findHeight(root->right);
    if(leftHeight>rightHeight) return leftHeight+1;
    else return rightHeight+1;
    
}

int main(){
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");
    struct  Node * root=createNode(5);
    struct  Node * p1=createNode(3);
    struct  Node * p2=createNode(6);
    struct  Node * p3=createNode(1);
    struct  Node * p4=createNode(4);
    root->left=p1;
    root->right=p2;
    p1->left=p3;
    p1->right=p4;
    printf("InOrder Traversal:  ");
    inorder(root);
    printf("\n");
    printf("PreOrder Traversal: ");
    preorder(root);
    printf("\n");
    printf("PostOrder Traversal:");
    postorder(root);
    printf("\n");
    
    root=insert(root,10);
    root=insert(root,9);
    root=insert(root,7);
    
    
    printf("InOrder Traversal after insertion:");
    inorder(root);
    printf("\n");
    printf("%d searching in tree.\n",70);
    if (search(root,70))
    {
        printf("value found\n");
    }
    else{
        printf("value not found.\n");
    }
    printf("Height of tree is %d\n",findHeight(root));
    return 0;
}