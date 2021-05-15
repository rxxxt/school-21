#include "../../includes/stack.h"

int	pop(t_stack *stack)
{
	t_node	*tmp;
	int		x;

	x = 0;
	if (!stack->size)
		write(STDERR_FILENO, "Error: stack underflow\n", 23);
	else
	{
		tmp = stack->head;
		x = tmp->data;
		stack->head = tmp->next;
		free(tmp);
		--stack->size;
	}
	return (x);
}

int	pop_back(t_stack *stack)
{
	t_node	*tmp;
	int		x;

	x = 0;
	if (!stack->size)
		write(STDERR_FILENO, "Error: stack underflow\n", 23);
	else
	{
		tmp = stack->head;
		while (tmp->next && tmp->next->next)
			tmp = tmp->next;
		x = tmp->next->data;
		free(tmp->next);
		tmp->next = NULL;
		--stack->size;
	}
	return (x);
}
