#include "../../includes/stack.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack && stack->head && stack->size > 1)
	{
		tmp = stack->head->data;
		stack->head->data = stack->head->next->data;
		stack->head->next->data = tmp;
	}
}

void	swap_a_and_b(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
