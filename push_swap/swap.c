#include "push_swap.h"

void  sa(c_llist  **head_a)
{
  if (!head_a || !(*head_a))
    return;

  c_llist *last;
  c_llist *second;
  last = (*head_a)->prev;
  second = (*head_a)->next;

  second->prev = last;
  last->next = second;
  (*head_a)->next = second->next;
  second->next->prev = *head_a;
  second->next = *head_a;
  (*head_a)->prev = second;

  *head_a = second;
}

void  sb(c_llist  **head_b)
{
  if (!head_b || !(*head_b))
    return;

  c_llist *last;
  c_llist *second;
  last = (*head_b)->prev;
  second = (*head_b)->next;

  second->prev = last;
  last->next = second;
  (*head_b)->next = second->next;
  second->next->prev = *head_b;
  second->next = *head_b;
  (*head_b)->prev = second;

  *head_b = second;
}

void ss(c_llist  **head_a, c_llist **head_b)
{
  sa(&head_a);
  sb(&head_b);
}
