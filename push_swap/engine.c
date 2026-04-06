#include "push_swap.h"

static int ft_sign(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void cost_formula(c_llist *node)
{
	if (!node)
		return ;
	if ((node->cost_a > 0 && node->cost_b > 0) || 
		(node->cost_a < 0 && node->cost_b < 0))
	{
		if (ft_sign(node->cost_a) > ft_sign(node->cost_b))
			node->total_cost = ft_sign(node->cost_a);
		else
			node->total_cost = ft_sign(node->cost_b);
	}
	else
	{
		node->total_cost = ft_sign(node->cost_a) + ft_sign(node->cost_b);
	}
}

c_llist *find_cheapest(c_llist *head)
{
	c_llist	*cheapest;
	c_llist	*tmp;

	if (!head)
		return (NULL);
	cheapest = head;
	tmp = head->next;
	while (1)
	{
		if (cheapest->total_cost > tmp->total_cost)
			cheapest = tmp;
		if (tmp == head || cheapest->total_cost <= 1)
			return (cheapest);
		tmp = tmp->next;
	}
}

void sort_three(c_llist **head)
{
	int	max_n;

	if (!head || !*head || is_sorted(*head))
		return ;
	max_n = find_max(*head)->index;
	if ((*head)->index == max_n)
		ra(head, 0);
	else if ((*head)->next->index == max_n)
		rra(head, 0);
	if ((*head)->index > (*head)->next->index)
		sa(head, 0);
}

void set_cost(c_llist *a, c_llist *b)
{
	int		size_a;
	int		size_b;
	c_llist	*tmp;

	if (!a || !b)
		return ;
	size_a = stack_size(a);
	size_b = stack_size(b);
	tmp = a;
	while (1)
	{
		if (tmp->above_median)
			tmp->cost_a = tmp->pos;
		else
			tmp->cost_a = (size_a - tmp->pos) * -1;
		if (tmp->target_node->above_median)
			tmp->cost_b = tmp->target_node->pos;
		else
			tmp->cost_b = (size_b - tmp->target_node->pos) * -1;
		cost_formula(tmp);
		tmp = tmp->next;
		if (tmp == a)
			break ;
	}
}
