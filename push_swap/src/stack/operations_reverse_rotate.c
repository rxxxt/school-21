#include "../../includes/stack.h"

void	reverse_rotate_a(t_stacks *stacks)
{
	if (stacks->a->size > 1)
		push(stacks->a, pop_back(stacks->a));
}

void	reverse_rotate_b(t_stacks *stacks)
{
	if (stacks->b->size > 1)
		push(stacks->b, pop_back(stacks->b));
}

void	reverse_rotate_a_and_b(t_stacks *stacks)
{
	reverse_rotate_a(stacks);
	reverse_rotate_b(stacks);
}