#include "../../includes/push_swap.h"

int get_last_data(t_stack *stack)
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

int get_next_data(t_stack *stack)
{
	int		data;
	t_node	*node;

	data = 0;
	node = stack->head;
	if (node->next != NULL)
		data = node->next->data;
	return (data);
}

int get_first_data(t_stack *stack)
{
	int		data;
	t_node	*node;

	data = 0;
	node = stack->head;
	if (node != NULL)
		data = node->data;
	return (data);
}

void	sorted_three_items(t_stacks *stacks)
{
	int	first;
	int	second;
	int third;

	first = get_first_data(stacks->a);
	second = get_next_data(stacks->a);
	third = get_last_data(stacks->a);
	if (first > second && first < third)
		swap_a(stacks);
	else if (first < second && first > third)
		reverse_rotate_a(stacks);
	else if (first > second && first > third)
		rotate_a(stacks);
	else if (first > second && second > third)
	{
		swap_a(stacks);
		reverse_rotate_a(stacks);
	}
	else if (first > second && first > third)
	{
		reverse_rotate_a(stacks);
		swap_a(stacks);
	}
}

void	easy_algorithm(t_stacks *stacks)
{
	if (stacks->a->size == 2 && !is_sorted(stacks->a->head))
		swap_a(stacks);
	else if (stacks->a->size == 3 && !is_sorted(stacks->a->head))
		sorted_three_items(stacks);
	else if (stacks->a->size == 3 && !is_sorted(stacks->a->head))
		sorted_three_items(stacks);
}