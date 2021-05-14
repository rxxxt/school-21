#include "../../includes/stack.h"

void	ft_exit(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

t_stacks 	*initialize_stacks(void)
{
	t_stacks	*stack;

	stack = malloc(sizeof(t_stacks));
	if (!stack)
		exit(EXIT_FAILURE);
	stack->a = malloc(sizeof(t_stack));
	if (!stack->a)
		exit(EXIT_FAILURE);
	stack->b = malloc(sizeof(t_stack));
	if (!stack->b)
		exit(EXIT_FAILURE);
	stack->a->head = NULL;
	stack->a->size = 0;
	stack->b->head = NULL;
	stack->b->size = 0;
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
	int 	size;

	while (--count > 0)
	{
		arr = ft_split(argv[count], ' ');
		size = ft_strarr_size(arr);
		while (--size >= 0)
		{
			nb = ft_atol(arr[size]);
			if (!correct_number(arr[size]) || nb > INT32_MAX || nb < INT32_MIN)
				ft_exit();
			push(stack, (int)nb);
		}
	}
}