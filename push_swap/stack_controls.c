#include "push_swap.c"

int is_duplicate(c_llist  *head,int key)
{
  c_llist *tmp;
  tmp = head;
  while(tmp)
  {
    if(tmp->value == key)
      return 1;
    tmp = tmp->next;
  }
  return 0;
}

void  node_indexing(c_llist *new_node)
{
  if(!new_node)
    return;

  new_node->index = new_node->prev->index+1;
}

c_llist *add_back(c_llist **head, c_llist *new_node)
{
  if(!head || !(*head) || !new_node)
    return NULL;

  c_llist last;
  last = (*head)->prev;
  
  (*head)->prev = new_node;
  new_node->next = *head;
  new_node->prev = last;
  last->next = new_node;

  return new_node;
}

c_llist *create_node(c_llist **head, int value)
{
  if(!head || !(*head) || !value)
    return NULL;

  int dup;
  dup = is_duplicate(head,value);

  if(dup == 1)
    return NULL;

  c_llist new_node;
  new_node = malloc(sizeof(c_llist) * 1);
  if(!new_node)
    return NULL;

  new_node->next = new_node->prev;
  new_node->prev = new_node->next;
  new_node->index = 0;
  new_node->value = value;

  add_back(&head,new_node);
  node_indexing(new_node);

  return new_node;
}
