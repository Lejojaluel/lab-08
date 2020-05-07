/******************/
/* Leroy Valencia */
/*    05/07/20    */
/*   CS-241-006   */
/******************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "binarytree.h"

struct TreeNode* createNode(int data)
{
  struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));

  node->data = data;

  node->left = NULL;
  node->right = NULL;

  return node;
}

struct TreeNode* insertBST(struct TreeNode* root, int data)
{
  /* If tree is empty then create new node */
  if(root == NULL)
  {
    return createNode(data);
  }
  if( data < root-> data)
  {
    root->left = insertBST(root->left, data);
  }
  else if( data > root->data)
  {
    root->right = insertBST(root->right, data);
  }
  return root;
}



int removeBST(struct TreeNode** rootRef, int data)
{
  struct TreeNode* heriarchy;
  struct TreeNode* previous;

  if(*rootRef == NULL) return 0;

  if(data < (*rootRef)->data)
  {
    return removeBST(&(*rootRef)->left, data);
  }
  else if(data > (*rootRef)->data)
  {
    return removeBST(&(*rootRef)->right, data);
  }
  else
  {
    struct TreeNode* temp;

    if((*rootRef)->right == NULL)
    {
      temp = *rootRef;
      *rootRef = (*rootRef)->left;
      free(temp);
    }
    else if((*rootRef)->left == NULL)
    {
      temp = *rootRef;
      *rootRef = (*rootRef)->right;
      free(temp);
    }
    else
    {
      heriarchy = (*rootRef)->left;
      previous = *rootRef;

      while(heriarchy->right != NULL)
      {
        previous = heriarchy;
        heriarchy = heriarchy->right;
      }

      (*rootRef)->data = heriarchy->data;

      if(previous != *rootRef)
      {
        previous->right = heriarchy->left;
      }
      else
      {
        previous->left = heriarchy->left;
      }

      free(heriarchy);
    }
    return 1;
  }
  return 0;
}


int minValueBST(struct TreeNode* root)
{
  struct TreeNode* temp = root;

  while(temp->left != NULL)
  {
    temp = temp->left;
  }
  return temp->data;
}

int maxDepth(struct TreeNode* root)
{
  if(root == NULL)
  {
    return 0;
  }
  else
  {
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return leftDepth > rightDepth ? leftDepth+1 : rightDepth+1;
  }
}

int isBalanced(struct TreeNode* root)
{
  int leftHeight, rightHeight;
  
  if(root == NULL) return 1;

  leftHeight = maxDepth(root->left);
  rightHeight = maxDepth(root->right);

  if(abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
  {
    return 1;
  }

  return 0;
}

int isBST(struct TreeNode* root)
{
  int min = -2147483647;
 int max = 2147483647;
  if(isBSTutil(root, min, max)) return 1;

  return 0;
}

int isBSTutil(struct TreeNode* root, int minKey, int maxKey)
{
  if(root == NULL) return 1;

  if(root-> data < minKey || root->data > maxKey) return 0;

  return isBSTutil(root->left, minKey, root->data) &&
          isBSTutil(root->right, root->data, maxKey);
}

void printTree(struct TreeNode* root)
{
  printTreeHelper(root);
  printf("\n");
}

void printTreeHelper(struct TreeNode* root)
{
    if(root != NULL)
  {
    printTreeHelper(root->left);
    printf("%d ", root->data);
    printTreeHelper(root->right);
  }
}

void printLeaves(struct TreeNode* root)
{
  printLeavesHelper(root);
  printf("\n");
}

void printLeavesHelper(struct TreeNode* root)
{
  if(root == NULL) return;

  if(!root->left && !root->right)
  {
    printf("%d ", root->data);
    return;
  }

  if(root->left != NULL) printLeavesHelper(root->left);
  if(root->right != NULL) printLeavesHelper(root->right);
}


void freeTree(struct TreeNode* root)
{
  if ( root != NULL)
  {
    freeTree(root->left);
    freeTree(root->right);
    free (root);
  }
}