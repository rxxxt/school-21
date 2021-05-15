#include "../../includes/stack.h"

void	push(t_stack *stack, int x)
{
	t_node	*new;

	if (stack->size == STACK_SIZE)
		write(STDERR_FILENO, "Error: stack overflow\n", 22);
	else
	{
		new = new_node(x);
		new->next = stack->head;
		stack->head = new;
		++stack->size;
	}
}

void	push_back(t_stack *stack, int x)
{
	t_node	*node;

	if (stack->size == STACK_SIZE)
		write(STDERR_FILENO, "Error: stack overflow\n", 22);
	else
	{
		node = stack->head;
		while (node->next)
			node = node->next;
		node->next = new_node(x);
		++stack->size;
	}
}
