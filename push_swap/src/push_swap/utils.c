#include "../../includes/push_swap.h"

int	get_last_data(t_stack *stack)
{
	int		data;
	t_node	*node;

	data = 0;
	node = stack->head;
	while (node)
	{
		if (node->next == NULL)
			data = node->data;
		node = node->next;
	}
	return (data);
}

int	max_data(t_node *node)
{
	int	max;

	max = node->data;
	while (node)
	{
		if (max < node->data)
			max = node->data;
		node = node->next;
	}
	return (max);
}

t_calc	initialize_calc(void)
{
	t_calc	calc;

	calc.action_a = R;
	calc.action_b = R;
	calc.count_a = 0;
	calc.count_b = 0;
	return (calc);
}
