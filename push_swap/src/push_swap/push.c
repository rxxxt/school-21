#include "../../includes/push_swap.h"

void	push_a(t_stacks *stacks)
{
	push(stacks->a, pop(stacks->b));
	write(STDOUT_FILENO, "pa\n", 3);
}

void	push_b(t_stacks *stacks)
{
	push(stacks->b, pop(stacks->a));
	write(STDOUT_FILENO, "pb\n", 3);
}
