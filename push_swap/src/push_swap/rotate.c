#include "../../includes/push_swap.h"

void	rotate_a(t_stacks *stacks)
{
	rotate(stacks->a);
	write(STDOUT_FILENO, "ra\n", 3);
}

void	rotate_b(t_stacks *stacks)
{
	rotate(stacks->b);
	write(STDOUT_FILENO, "rb\n", 3);
}

void	rotate_a_b(t_stacks *stacks)
{
	rotate(stacks->a);
	rotate(stacks->b);
	write(STDOUT_FILENO, "rr\n", 3);
}
