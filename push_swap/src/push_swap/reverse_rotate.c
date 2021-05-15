#include "../../includes/push_swap.h"

void	reverse_rotate_a(t_stacks *stacks)
{
	reverse_rotate(stacks->a);
	write(STDOUT_FILENO, "rra\n", 4);
}

void	reverse_rotate_b(t_stacks *stacks)
{
	reverse_rotate(stacks->b);
	write(STDOUT_FILENO, "rrb\n", 4);
}

void	reverse_rotate_a_b(t_stacks *stacks)
{
	reverse_rotate(stacks->a);
	reverse_rotate(stacks->b);
	write(STDOUT_FILENO, "rrr\n", 4);
}
