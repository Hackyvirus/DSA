#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
Node * insert (Node * root, int data){
  if(root==NULL){
    return newNode(data);
  }
  if(root->data > data){
    root->left = insert(root->left,data);
  }else if(root->data < data){
    root->right = insert(root->right,data);
  }
  return root;
}


void inOrder(Node * root){
  if(root!=NULL){
    inOrder(root->left);
    printf("%d \n",root->data);
    inOrder(root->right);
  }
}

void PreOrder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

int main() {
    Node *root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 1);
    insert(root, 4);
    insert(root, 7);
    insert(root, 2);

    printf("PreOrder traversal after insertion: ");
    PreOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");

    return 0;
}
