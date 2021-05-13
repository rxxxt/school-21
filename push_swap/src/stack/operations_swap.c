#include "../../includes/stack.h"

static void	swap_top_two(t_stack *stack)
{
	int	tmp;

	if (stack && stack->head && stack->size > 1)
	{
		tmp = stack->head->data;
		stack->head->data = stack->head->next->data;
		stack->head->next->data = tmp;
	}
}

void	swap_a(t_stacks *stacks)
{
	swap_top_two(stacks->a);
}

void	swap_b(t_stacks *stacks)
{
	swap_top_two(stacks->b);
}

void	swap_a_and_b(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}