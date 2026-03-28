#include "push_swap.c"

void  update_lindex(c_llist **head,int flag)
{
  if(!head || !(*head) || flag!=-1 || flag!=1)
    return;

  c_llist *tmp;
  tmp = *head;
  if(flag == 1)
  {
   while(tmp->index != 1)
    {
      tmp->index = tmp->index-1;
      tmp = tmp->next;
    }
    tmp->index = tmp->prev->index+1;
  }
  else if(flag == -1)
  {
    int current;
    current = tmp->index;
    while(tmp->index + 1 != current)
    {
      tmp->index = tmp->next->index;
      tmp = tmp->next;
    }
    tmp->index = tmp->index+1;
  }
}

static int is_duplicate(c_llist  *head,int key)
{
  c_llist *tmp;
  tmp = head;
  while(head->next != tmp)
  {
    if(head->value == key)
      return 1;
    head = head->next;
  }
  return 0;
}

c_llist *add_back(c_llist **head, c_llist *new_node)
{
  if(!head || !(*head) || !new_node)
    return NULL;

  c_llist *last;
  last = (*head)->prev;
  
  (*head)->prev = new_node;
  new_node->next = *head;
  new_node->prev = last;
  last->next = new_node;
  new_node->index = new_node->prev->index+1;

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

  c_llist *new_node;
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
