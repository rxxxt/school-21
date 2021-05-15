#include "../../includes/stack.h"

void	ft_exit(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

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

void	fill_stack(t_stack *stack, char **argv, int count)
{
	long	nb;
	char	**arr;
	int		size;

	while (--count > 0)
	{
		arr = ft_split(argv[count], ' ');
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
