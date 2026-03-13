#include "push_swap.h"

void  sa(c_llist  **head_a,int flag)
{
  if (!head_a || !(*head_a) || (*head_a)->next == *head_a)
    return;

  c_llist *last;
  c_llist *second;
  c_llist *first;

  first = *head_a;
  last = (*head_a)->prev;
  second = (*head_a)->next;


  first->next = second->next;
  second->next->prev = first;
  first->prev = second;
  last->next = second;
  second->prev = last;
  second->next = first;  

  *head_a = second;
  if(flag != 1)
    write(1,"sa\n",3);
}

void  sb(c_llist  **head_b, int flag)
{
  if (!head_b || !(*head_b) || (*head_b)->next == *head_b )
    return;

  c_llist *last;
  c_llist *second;
  c_llist *first;

  first = *head_b;
  last = (*head_b)->prev;
  second = (*head_b)->next;

  first->next = second->next;
  second->next->prev = first;
  first->prev = second;
  last->next = second;
  second->prev = last;
  second->next = first;

  *head_b = second;
  if(flag != 1)
    write(1,"sb\n",3);
}

void ss(c_llist  **head_a, c_llist **head_b)
{
  sa(head_a,1);
  sb(head_b,1);
  write(1,"ss\n",3);
}
