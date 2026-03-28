#include "push_swap.h"

void  ra(c_llist  **head_a, int flag)
{
  if(!head_a || !(*head_a))
    return;

  c_llist *second;
  second = (*head_a)->next;

  *head_a = second;
  if(flag!= 1)
    write(1,"ra\n",3);
}

void  rb(c_llist  **head_b, int flag)
{
  if(!head_b || !(*head_b))
    return;

  c_llist *second;
  second = (*head_b)->next;

  *head_b = second;
  if(flag!=1)
    write(1,"rb\n",3);
}

void rr(c_llist **head_a,c_llist  **head_b)
{
  ra(head_a,1);
  rb(head_b,1);
  write(1,"rr\n",3);
}

