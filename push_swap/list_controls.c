#include "push_swap.h"

c_llist *create_node(int num)
{
  c_llist *new_node;
  new_node = malloc(sizeof(c_llist) * 1);
  if(!new_node)
    return NULL;

  new_node->num = num;
  new_node->index = -1;
  new_node->pos = -1;
  new_node->cost_a = -1;
  new_node->cost_b = -1;
  new_node->total_cost = -1;
  new_node->above_median = false;
  new_node->target_node = NULL;
  new_node->next = new_node;
  new_node->prev = new_node;

  return new_node;
}

c_llist *add_new_node(int num,  c_llist **head)
{
  if(!head)
    return NULL;

  if(!*head)
    return  (*head = create_node(num));

  c_llist *tail;
  c_llist *new_node;

  new_node = create_node(num);
  tail = (*head)->prev;
  
  new_node->prev = tail;
  new_node->next = *head;
  tail->next = new_node;
  (*head)->prev = new_node;

  return new_node;
}

void  freenclean_list(c_llist **head)
{
  if(!head)
    return;

  c_llist *current;
  c_llist *prev;

  current = (*head)->next;
  prev = NULL;

  while(current!=*head)
  {
    prev = current;
    current = current->next;
    free(prev);
  }
  free(*head);
  *head = NULL;

  return;
}
