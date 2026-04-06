#include "push_swap.h"

static void	min_on_top(c_llist **a)
{
	c_llist	*min;
	bool	direction;

	min = find_min(*a);
	direction = min->above_median;
	while (*a != min)
	{
		if (direction)
			ra(a, 0);
		else
			rra(a, 0);
	}
}

static void	back_to_a(c_llist **a, c_llist **b)
{
	c_llist	*target;
	bool	direction;

	while (*b)
	{
		upd_position(*a);
		upd_position(*b);
		upd_median(*a, stack_size(*a));
		upd_median(*b, stack_size(*b));
		
		set_target_b(*a, *b);
		target = (*b)->target_node;
		direction = target->above_median;
		
		while (*a != target)
		{
			if (direction)
				ra(a, 0);
			else
				rra(a, 0);
		}
		pa(a, b);
	}
}

void	sort_stacks(c_llist **a, c_llist **b)
{
	int	size_a;

	upd_position(*a);
	size_a = stack_size(*a);
	if (size_a > 3 && !is_sorted(*a))
		pb(a, b);
	if (size_a > 4 && !is_sorted(*a))
		pb(a, b);
	while (stack_size(*a) > 3 && !is_sorted(*a))
	{
		upd_position(*a);
		upd_position(*b);
		upd_median(*a, stack_size(*a));
		upd_median(*b, stack_size(*b));
		set_target_a(*a, *b);
		set_cost(*a, *b);
		move_nodes(a, b);
	}
	sort_three(a);
	back_to_a(a, b);
	upd_position(*a);
	upd_median(*a, stack_size(*a));
	min_on_top(a);
}
