#include "push_swap.h"

static void	rotate_both(c_llist **a, c_llist **b, c_llist *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		cheapest->cost_a--;
		cheapest->cost_b--;
		rr(a, b);
	}
	upd_position(*a);
	upd_position(*b);
}

static void	rev_rotate_both(c_llist **a, c_llist **b, c_llist *cheapest)
{
	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		cheapest->cost_a++;
		cheapest->cost_b++;
		rrr(a, b);
	}
	upd_position(*a);
	upd_position(*b);
}

void	move_nodes(c_llist **a, c_llist **b)
{
	c_llist	*cheapest;

	cheapest = find_cheapest(*a);
	if (cheapest->cost_a > 0 && cheapest->cost_b > 0)
		rotate_both(a, b, cheapest);
	else if (cheapest->cost_a < 0 && cheapest->cost_b < 0)
		rev_rotate_both(a, b, cheapest);
	finish_rotation(a, cheapest->cost_a, 'a');
	finish_rotation(b, cheapest->cost_b, 'b');
	pb(a, b);
}
