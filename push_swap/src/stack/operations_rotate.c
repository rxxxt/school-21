#include "../../includes/stack.h"

void	rotate(t_stack *stack)
{
	if (stack->size > 1)
		push_back(stack, pop(stack));
}

void	rotate_a_and_b(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
