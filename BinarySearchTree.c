#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node* left;
  int data;
  struct node* right;
};

void treemaker(struct node* parent, struct node* child){
  if(child->data < parent->data && parent->left == NULL){
    parent->left = child;
  }
  else if(child->data < parent->data && parent->left!=NULL){
    treemaker( parent->left, child);
  }
  if(child->data > parent->data && parent->right == NULL){
    parent->right = child;
  }
  else if(child->data > parent->data && parent->right!=NULL){
    treemaker( parent->right, child);
  }
}

void Inorder(struct node* nd){
  if(nd != NULL){
    if(nd->left != NULL){
    Inorder(nd->left);
  }
  printf("%d",nd->data);
  if(nd->right != NULL){
    Inorder(nd->right);
  }
}
}

int main(){
  struct node* root;
  struct node* newnode;
  char choice='y';
  int flag = 0;

  while(choice != 'n'){
  printf("Enter the element:\n");
  newnode = (struct node*) malloc (sizeof(struct node));
  newnode->left = NULL;
  newnode->right = NULL;
  scanf("%d",&newnode->data);
  if(flag==0){
    root = newnode;
    flag = 1;
  }
  treemaker(root, newnode);
  printf("Do you wish to enter more elements?(y/n)\n");
  scanf(" %c",&choice);
}

Inorder(root);

}
