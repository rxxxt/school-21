#include "../../includes/stack.h"

void	push_a(t_stacks *stacks)
{
	if (stacks->b->size > 0)
		push(stacks->a, pop(stacks->b));
}

void	push_b(t_stacks *stacks)
{
	if (stacks->a->size > 0)
		push(stacks->b, pop(stacks->a));
}