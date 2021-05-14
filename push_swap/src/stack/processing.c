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
	(stack->a)->head = NULL;
	(stack->a)->size = 0;
	(stack->b)->head = NULL;
	(stack->b)->size = 0;
	return (stack);
}

void	processing(char *line, t_stacks *stacks)
{
	if (!ft_strcmp(line, "sa") && !line[2])
		swap_a(stacks);
	else if (!ft_strcmp(line, "sb") && !line[2])
		swap_b(stacks);
	else if (!ft_strcmp(line, "ss") && !line[2])
		swap_a_and_b(stacks);
	else if (!ft_strcmp(line, "pa") && !line[2])
		push_a(stacks);
	else if (!ft_strcmp(line, "pb") && !line[2])
		push_b(stacks);
	else if (!ft_strcmp(line, "ra") && !line[2])
		rotate_a(stacks);
	else if (!ft_strcmp(line, "rb") && !line[2])
		rotate_b(stacks);
	else if (!ft_strcmp(line, "rr") && !line[2])
		rotate_a_and_b(stacks);
	else if (!ft_strcmp(line, "rra") && !line[3])
		reverse_rotate_a(stacks);
	else if (!ft_strcmp(line, "rrb") && !line[3])
		reverse_rotate_b(stacks);
	else if (!ft_strcmp(line, "rrr") && !line[3])
		reverse_rotate_a_and_b(stacks);
	else
		ft_exit();
}