#include "../../includes/stack.h"

t_node	*new_node(int x)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->data = x;
	new->next = NULL;
	return (new);
}

t_stack	*initialize_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		exit(EXIT_FAILURE);
	stack->head = NULL;
	stack->size = 0;
	return (stack);
}

t_stack	*copy_stack(t_stack *stack)
{
	t_stack	*copy;
	t_node	*node;

	copy = initialize_stack();
	if (stack && stack->head)
	{
		node = stack->head;
		while (node)
		{
			push_back(copy, node->data);
			node = node->next;
		}
	}
	return (copy);
}

void	fill_stack(t_stack *stack, char **argv, int count)
{
	long	nb;
	char	**arr;
	int		size;

	while (--count > 0)
	{
		arr = ft_split(argv[count], ' ');
		if (!arr || !*arr)
			ft_exit();
		size = (int)ft_strarr_size(arr);
		while (--size >= 0)
		{
			nb = ft_atol(arr[size]);
			if (!correct_number(arr[size]) || nb > INT32_MAX || nb < INT32_MIN)
				ft_exit();
			push(stack, (int)nb);
		}
		ft_free_array(arr);
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*node;

	while (stack->head)
	{
		node = stack->head;
		stack->head = stack->head->next;
		free(node);
	}
	free(stack);
}
