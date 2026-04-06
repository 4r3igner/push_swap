#include "push_swap.h"

static c_llist	*get_target_a(c_llist *node_a, c_llist *b)
{
	c_llist	*tmp_b;
	c_llist	*target;
	long	best_match;

	best_match = LONG_MIN;
	tmp_b = b;
	target = NULL;
	while (1)
	{
		if (tmp_b->index < node_a->index && tmp_b->index > best_match)
		{
			best_match = tmp_b->index;
			target = tmp_b;
		}
		tmp_b = tmp_b->next;
		if (tmp_b == b)
			break ;
	}
	if (best_match == LONG_MIN)
		return (find_max(b));
	return (target);
}

void	set_target_a(c_llist *a, c_llist *b)
{
	c_llist	*tmp_a;

	if (!a || !b)
		return ;
	tmp_a = a;
	while (1)
	{
		tmp_a->target_node = get_target_a(tmp_a, b);
		tmp_a = tmp_a->next;
		if (tmp_a == a)
			break ;
	}
}

static c_llist	*get_target_b(c_llist *node_b, c_llist *a)
{
	c_llist	*tmp_a;
	c_llist	*target;
	long	best_match;

	best_match = LONG_MAX;
	tmp_a = a;
	target = NULL;
	while (1)
	{
		if (tmp_a->index > node_b->index && tmp_a->index < best_match)
		{
			best_match = tmp_a->index;
			target = tmp_a;
		}
		tmp_a = tmp_a->next;
		if (tmp_a == a)
			break ;
	}
	if (best_match == LONG_MAX)
		return (find_min(a));
	return (target);
}

void	set_target_b(c_llist *a, c_llist *b)
{
	c_llist	*tmp_b;

	if (!a || !b)
		return ;
	tmp_b = b;
	while (1)
	{
		tmp_b->target_node = get_target_b(tmp_b, a);
		tmp_b = tmp_b->next;
		if (tmp_b == b)
			break ;
	}
}
