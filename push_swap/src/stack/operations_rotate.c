#include "../../includes/stack.h"

void	rotate_a(t_stacks *stacks)
{
	if (stacks->a->size > 1)
		push_back(stacks->a, pop(stacks->a));
}

void	rotate_b(t_stacks *stacks)
{
	if (stacks->b->size > 1)
		push_back(stacks->b, pop(stacks->b));
}

void	rotate_a_and_b(t_stacks *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
}