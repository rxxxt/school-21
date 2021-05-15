#include "../../includes/push_swap.h"

void	swap_a(t_stacks *stacks)
{
	swap(stacks->a);
	write(STDOUT_FILENO, "sa\n", 3);
}

void	swap_b(t_stacks *stacks)
{
	swap(stacks->b);
	write(STDOUT_FILENO, "sb\n", 3);
}

void	swap_a_b(t_stacks *stacks)
{
	swap(stacks->a);
	swap(stacks->b);
	write(STDOUT_FILENO, "ss\n", 3);
}
