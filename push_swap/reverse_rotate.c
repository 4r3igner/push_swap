#include "push_swap.h"

void  rra(c_llist **head_a,int flag)
{
  if(!head_a || !(*head_a))
    return;

  c_llist *last;
  last = (*head_a)->prev;
  *head_a = last;
  
  if(flag != 1)
    write(1,"rra\n",4);
}

void  rrb(c_llist **head_b,int flag)
{
  if(!head_b || !(*head_b))
    return;

  c_llist *last;
  last = (*head_b)->prev;
  *head_b = last;
  
  if(flag != 1)
    write(1,"rrb\n",4);
}

void rrr(c_llist  **head_a,c_llist **head_b)
{
  rra(head_a,1);
  rrb(head_b,1);
  write(1,"rrr\n",4);
}
