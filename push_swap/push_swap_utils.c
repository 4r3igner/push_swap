#include "push_swap.h"

c_llist *find_min(c_llist  *head)
{
  if(!head)
    return NULL;

  if(head->index == 0)
    return head;
  c_llist *smallest_n;
  c_llist *next_n;
  smallest_n = head;
  next_n = head->next;
  while(next_n!=head)
  {
    if(smallest_n->index > next_n->index)
      smallest_n = next_n;
    next_n = next_n->next;
  }

  return smallest_n;
}

c_llist *find_max(c_llist  *head)
{
  if(!head)
    return NULL;

  c_llist *biggest_n;
  c_llist *next_n;
  biggest_n = head;
  next_n  = head->next;

  while(next_n!=head)
  {
    if(biggest_n->index < next_n->index)
      biggest_n = next_n;
    next_n = next_n->next;
  } 

  return biggest_n;
}

bool  is_sorted(c_llist *head)
{
  if(!head)
    return true;

  c_llist *tmp;
  tmp = head;
  
  
  while(tmp!=head->prev)
  {
    if(tmp->index > tmp->next->index)
      return false;
    tmp = tmp->next;
  }

  return true;
}

int	stack_size(c_llist *head)
{
	int		count;
	c_llist	*tmp;

	if (!head)
		return (0);
	count = 0;
	tmp = head;
	while (1)
	{
		count++;
		tmp = tmp->next;
		if (tmp == head)
			break ;
	}
	return (count);
}

void	finish_rotation(c_llist **stack, int cost, char name)
{
	while (cost > 0)
	{
		if (name == 'a')
			ra(stack, 0);
		else if (name == 'b')
			rb(stack, 0);
		cost--;
	}
	while (cost < 0)
	{
		if (name == 'a')
			rra(stack, 0);
		else if (name == 'b')
			rrb(stack, 0);
		cost++;
	}
}
