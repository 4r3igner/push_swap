#include "push_swap.h"

void  error_handler()
{
  write(2,"Error\n",6);
  exit(1);
}

void  upd_position(c_llist  *head)
{
  if(!head)
    return;

  int i;
  i = 0;
  c_llist *tmp;
  tmp = head;
  while(1)
  {
    tmp->pos = i++;
    tmp = tmp->next;
    if(tmp  ==  head)
      break;
  }

  return;
}

void	upd_median(c_llist *head, int stack_s)
{
	int		med_pos;
	c_llist	*tmp;

	if (!head)
		return ;
	med_pos = stack_s / 2;
	tmp = head;
	while (1)
	{
		if (tmp->pos <= med_pos)
			tmp->above_median = true;
		else
			tmp->above_median = false;
		tmp = tmp->next;
		if (tmp == head)
			break ;
	}
}
