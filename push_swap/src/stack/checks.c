#include "../../includes/stack.h"

void	ft_exit(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_node *head)
{
	while (head && head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

int	correct_number(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	sorting_the_list(t_stack *stack)
{
	t_node	*node;
	int		tmp;

	node = stack->head;
	while (!is_sorted(node))
	{
		while (node->next)
		{
			if (node->data > node->next->data)
			{
				tmp = node->data;
				node->data = node->next->data;
				node->next->data = tmp;
			}
			node = node->next;
		}
		node = stack->head;
	}
}

int	there_are_duplicates(t_stack *stack)
{
	t_node	*node;

	sorting_the_list(stack);
	node = stack->head;
	while (node->next)
	{
		if (node->data == node->next->data)
			return (1);
		node = node->next;
	}
	return (0);
}
