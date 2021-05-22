#include "../../includes/checker.h"

void	processing(char *line, t_stacks *stacks)
{
	if (!ft_strcmp(line, "sa") && !line[2])
		swap(stacks->a);
	else if (!ft_strcmp(line, "sb") && !line[2])
		swap(stacks->b);
	else if (!ft_strcmp(line, "ss") && !line[2])
		swap_a_and_b(stacks->a, stacks->b);
	else if (!ft_strcmp(line, "pa") && !line[2])
		push_a_pop_b(stacks->a, stacks->b);
	else if (!ft_strcmp(line, "pb") && !line[2])
		push_b_pop_a(stacks->a, stacks->b);
	else if (!ft_strcmp(line, "ra") && !line[2])
		rotate(stacks->a);
	else if (!ft_strcmp(line, "rb") && !line[2])
		rotate(stacks->b);
	else if (!ft_strcmp(line, "rr") && !line[2])
		rotate_a_and_b(stacks->a, stacks->b);
	else if (!ft_strcmp(line, "rra") && !line[3])
		reverse_rotate(stacks->a);
	else if (!ft_strcmp(line, "rrb") && !line[3])
		reverse_rotate(stacks->b);
	else if (!ft_strcmp(line, "rrr") && !line[3])
		reverse_rotate_a_and_b(stacks->a, stacks->b);
	else
		ft_exit();
}

void	executing_instructions(t_stacks *stacks)
{
	char	*line;
	int		sign;

	sign = 1;
	while (sign)
	{
		sign = get_next_line(STDIN_FILENO, &line);
		if (sign == -1)
			ft_exit();
		else if (sign == 1)
			processing(line, stacks);
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	t_stack		*copy;

	if (argc > 1)
	{
		stacks.a = initialize_stack();
		stacks.b = initialize_stack();
		fill_stack(stacks.a, argv, argc);
		copy = copy_stack(stacks.a);
		if (stacks.a->size > 1 && there_are_duplicates(copy))
			ft_exit();
		free_stack(copy);
		executing_instructions(&stacks);
		if (is_sorted(stacks.a->head) && stacks.b->size == 0)
			write(STDOUT_FILENO, "OK\n", 3);
		else
			write(STDOUT_FILENO, "KO\n", 3);
		free_stack(stacks.a);
		free_stack(stacks.b);
	}
	return (0);
}
