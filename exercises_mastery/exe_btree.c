#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct binary_tree
{
  int                   value;
  struct  binary_tree   *left;
  struct  binary_tree   *right;
}b_tree;

typedef struct s_queue
{
  b_tree          *node;
  struct s_queue  *next;
}t_queue;

b_tree  *create_node(int value)
{
  if(!value)
    return NULL;

  b_tree  *new_node;
  new_node = malloc(sizeof(b_tree));
  if(!new_node)
    return NULL;

  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

b_tree  *insert_node(b_tree *root, int value)
{
  if (!root)
    return (create_node(value));

  if (value < root->value)
    root->left = insert_node(root->left,value);
  else if (value > root->value)
    root->right = insert_node(root->right,value);

  return root;
}

b_tree  *search_node(b_tree *root, int key)
{
  if(!root || root->value == key)
    return root;
  
  if(key < root->value)
    return(search_node(root->left,key));

  return(search_node(root->right,key));
}

void  print_inorder(b_tree  *root)
{
  if(root == NULL)
    return;

  print_inorder(root->left);

  printf("%d ",root->value);

  print_inorder(root->right);
}

void  print_descending(b_tree *root)
{
  if(root == NULL)
    return;

  print_descending(root->right);

  printf("%d ",root->value);

  print_descending(root->left);
}

int tree_height(b_tree *root)
{
  if (!root)
    return 0;

  int left = 0;
  int right = 0;

  left += tree_height(root->left);
  right += tree_height(root->right);

  
  if(left > right)
    return left + 1;
  else
    return right + 1;
}

b_tree  *find_min_node(b_tree *root)
{
  b_tree  *current = root;
  while(current && current->left != NULL)
    current = current->left;
  return  current;
}

b_tree  *delete_node(b_tree *root, int key)
{
  if(!root)
    return NULL;
  else if (key < root->value)
      root->left = delete_node(root->left,key);
  else if (key > root->value)
      root->right = delete_node(root->right, key);
  else
  {
    //Case one: no child
    if(!(root->left) && !(root->right))
    {
      free(root);
      root = NULL;
    }
    //Case two: one child
    else if(!(root->left))
    {
      b_tree  *tmp = root;
      root = root->right;
      free(tmp);
    }
    else if(!(root->right))
    {
      b_tree  *tmp = root;
      root = root->left;
      free(tmp);
    }
    //Third case: two cildren
    else
    {
      b_tree  *tmp = find_min_node(root);
      root->value = tmp->value;
      root->right = delete_node(root->right,tmp->value);
    }
  }
  return root;
}

b_tree  *rotate_left(b_tree *x)
{
  b_tree  *y = x->right;
  b_tree  *orphan = y->left;

  y->left = x;
  x->right = orphan;

  return y;
}

b_tree  *find_lca(b_tree  *root, int p, int q)
{
  if(!root)
    return NULL;
  
  if(p > root->value && q > root->value)
    return find_lca(root->right,p,q);
  if(p < root->value && q < root->value)
    return find_lca(root-left,p,q);

  return root;
}

void enqueue(t_queue  **head, b_tree *tree_node)
{

}

b_tree  *dequeue(t_queue  **head)
{

}

int main()
{
  b_tree  *root = NULL;
  int data [] = {10, 15, 5, 20, 7, 35, 13, 2, 6, 18, 23};
  int size = sizeof(data)/sizeof(data[0]);

  int i = 0;
  while(i < size)
  {
    root = insert_node(root,data[i]);
    i++;
  }

  print_inorder(root);
  printf("\n");
  delete_node(root,18);
  print_descending(root);

  printf("\n%d", tree_height(root));

  return 0;
}


