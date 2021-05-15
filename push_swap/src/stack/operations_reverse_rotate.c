#include "../../includes/stack.h"

void	reverse_rotate(t_stack *stack)
{
	if (stack->size > 1)
		push(stack, pop_back(stack));
}

void	reverse_rotate_a_and_b(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
