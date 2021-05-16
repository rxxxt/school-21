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

void	sorting_three_items(t_stacks *stacks)
{
	int	first;
	int	second;
	int third;

//	first = get_first_data(stacks->a);
//	second = get_next_data(stacks->a);
//	third = get_last_data(stacks->a);
	first = stacks->a->head->data;
	second = stacks->a->head->next->data;
	third = stacks->a->head->next->next->data;
	if (first > second && first < third)
		swap_a(stacks);
	else if (first < second && first > third)
		reverse_rotate_a(stacks);
	else if (first > second && second < third)
		rotate_a(stacks);
	else if (first > second && second > third)
	{
		swap_a(stacks);
		reverse_rotate_a(stacks);
	}
	else if (first < second && second > third)
	{
		reverse_rotate_a(stacks);
		swap_a(stacks);
	}
}

void	sorting_more_than_three_items(t_stacks *stacks)
{
	
}

void	easy_algorithm(t_stacks *stacks)
{
	if (stacks->a->size == 2)
		swap_a(stacks);
	else if (stacks->a->size == 3)
		sorting_three_items(stacks);
	else
		sorting_more_than_three_items(stacks);
}
