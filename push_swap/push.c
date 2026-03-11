#include "push_swap.h"


void pa(c_llist **head_a, c_llist **head_b)
{
  if(!head_a || !(*head_a) || !head_b || !(*head_b))
    return;

  c_llist *second_a;
  second_a = (*head)->next;

  second_a->prev = (*head_a)->prev;
  (*head_a)->prev->next = second_a;
  
  (*head_b)->prev->next = *head_a;
  (*head_a)->prev = (*head_b)->prev;
  (*head_a)->next = *head_b;
  (*head_b)->prev = *head_a;

  *head_a = second_a;
  *head_b = *head_a;
}

void pb(c_llist **head_a, c_llist **head_b)
{
  if(!head_a || !(*head_a) || !head_b || !(*head_b))
    return;

  c_llist *second_b;
  second_b = (*head)->next;

  second_b->prev = (*head_b)->prev;
  (*head_b)->prev->next = second_b;
  
  (*head_a)->prev->next = *head_b;
  (*head_b)->prev = (*head_a)->prev;
  (*head_b)->next = *head_a;
  (*head_a)->prev = *head_b;

  *head_b = second_b;
  *head_a = *head_b;
}
