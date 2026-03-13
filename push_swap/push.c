#include "push_swap.h"

static c_llist  *extract(c_llist **head)
{
  c_llist *second;
  c_llist *extracted;
  c_llist *last;
  extracted = (*head);
  second = (*head)->next;
  last = (*head)->prev;

  if(second == extracted)
  {
    *head = NULL;
    return extracted;
  }
  last->next = second;
  second->prev = last;

  extracted->prev = extracted;
  extracted->next = extracted;

  *head = second;

  return extracted;
}

static void insert(c_llist  *node,c_llist **stack)
{
  if(*stack == NULL)
  {
    *stack = node;
    return;
  }

  (*stack)->prev->next = node;
  node->prev = (*stack)->prev;
  node->next = *stack;
  (*stack)->prev = node;

  *stack = node;
}

void pa(c_llist **head_a,c_llist  **head_b)
{
  if(!head_b || !(*head_b))
    return;

  insert(extract(head_b),head_a);
  
  write(1,"pa\n",3);
}

void pb(c_llist **head_a,c_llist **head_b)
{
  if(!head_a || !(*head_a))
    return;

  insert(extract(head_a),head_b);

  write(1,"pb\n",3);
}
/*
static void more_and_null(c_llist **head_1,c_llist  **head_2, c_llist *second)
{
  (*head_1)->prev->next = second;
  second->prev = (*head_1)->prev;

  (*head_1)->prev = *head_1;
  (*head_1)->next = *head_1;

  *head_2 = *head_1;
  *head_1 = second; 
}

static void one_and_more(c_llist  **head_1, c_llist **head_2, c_llist *second)
{
  (*head_2)->prev->next = second;
  second->prev = (*head_2)->prev;
  (*head_2)->prev = second;
  second->next = *head_2;
  *head_2 = second;

  *head_1 = NULL;
}

static void more_than_1(c_llist **head_1,c_llist  **head_2, c_llist *second)
{
  (*head_1)->prev->next =(*head)->next;
  (*head_1)->next->prev = (*head)->prev;

  (*head_2)->prev->next = *head_1;
  (*head_1)->prev = (*head_2)->prev;
  (*head_1)->next = *head_2;
  (*head_2)->prev = *head_1;

  *head_2 = *head_1;
  *head_1 = second;
}
*/

