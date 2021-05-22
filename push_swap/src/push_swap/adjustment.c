#include "../../includes/push_swap.h"

static void	ra_or_rra(t_stacks *stacks)
{
	stacks->calc.count_a--;
	if (stacks->calc.action_a == R)
		rotate_a(stacks);
	else if (stacks->calc.action_a == RR)
		reverse_rotate_a(stacks);
}

static void	rb_or_rrb(t_stacks *stacks)
{
	stacks->calc.count_b--;
	if (stacks->calc.action_b == R)
		rotate_b(stacks);
	else if (stacks->calc.action_b == RR)
		reverse_rotate_b(stacks);
}

static void	rr_or_rrr(t_stacks *stacks)
{
	stacks->calc.count_a--;
	stacks->calc.count_b--;
	if (stacks->calc.action_a == R)
		rotate_a_b(stacks);
	else if (stacks->calc.action_a == RR)
		reverse_rotate_a_b(stacks);
}

void	last_adjustment(t_stacks *stacks)
{
	t_node	*node;

	node = stacks->a->head;
	stacks->calc = initialize_calc();
	while (node && !is_sorted(node))
	{
		stacks->calc.count_a++;
		node = node->next;
	}
	optimization(stacks, stacks->calc);
	while (stacks->calc.count_a)
		ra_or_rra(stacks);
}

void	adjustment(t_stacks *stacks)
{
	while (stacks->calc.count_a || stacks->calc.count_b)
	{
		if (stacks->calc.action_a == stacks->calc.action_b
			&& stacks->calc.count_a && stacks->calc.count_b)
			rr_or_rrr(stacks);
		else if (stacks->calc.count_b)
			rb_or_rrb(stacks);
		else if (stacks->calc.count_a)
			ra_or_rra(stacks);
	}
}
