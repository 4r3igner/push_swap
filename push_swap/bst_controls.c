#include "push_swap.h"

t_binary  *create_bst(int  num,  c_llist *head)
{
  t_binary  *new_root;
  new_root = malloc(sizeof(t_binary) * 1);
  if(!new_root)
    return NULL;

  new_root->root = num;
  new_root->index = -1;
  new_root->ref2list = head;
  new_root->left = NULL;
  new_root->right = NULL;

  return new_root;
}

t_binary  *insert_bst(int num,  t_binary  *root, c_llist *head,  int *is_dupp)
{
  if(!root)
    return  (create_bst(num,head));

  if(num == root->root)
  {
    (*is_dupp)++;
    return root;
  }
  else  if(num  < root->root)
    root->left = insert_bst(num,  root->left, head, is_dupp);
  else  if(num  > root->root)
    root->right = insert_bst(num, root->right,  head, is_dupp);
  
  return root;
}

void  sort_bst(t_binary *root,  int *index)
{
  if(!root)
    return;

  sort_bst(root->left,  index);

  root->ref2list->index = *index;
  (*index)++;

  sort_bst(root->right, index);
}

void  freenclean_bst(t_binary **root)
{
  if(!root || !*root)
    return;

  freenclean_bst(&((*root)->left));
  freenclean_bst(&((*root)->right));

  free(*root);
  *root = NULL;
}

