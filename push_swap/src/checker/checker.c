#include "../../includes/push_swap.h"

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

#include <stdio.h>
void	print(t_stacks *stacks)
{
	t_node	*a;
	t_node	*b;

	a = stacks->a->head;
	b = stacks->b->head;
	printf("  стэк а  |  стэк б  \n");
	fflush(stdout);
	while (a || b)
	{
		if (a)
		{
			printf("%10d|", a->data);
			fflush(stdout);
		}
		if (b)
		{
			printf("%10d\n", b->data);
			fflush(stdout);
		}
		else
			write(1, "\n", 1);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	printf("размер стэка а = %d | размер стэка а = %d\n", stacks->a->size,
		stacks->b->size);
}

void	executing_instructions(t_stacks *stacks)
{
	char	*line;
	int 	flag;

	flag = 1;
	print(stacks);
	while (flag)
	{
		flag = get_next_line(STDIN_FILENO, &line);
		if (flag == -1)
			ft_exit();
		else if (flag)
		{
			processing(line, stacks);
			print(stacks);
			free(line);
		}
	}
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

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc > 1)
	{
		stacks = initialize_stacks();
		if (!stacks)
			exit(EXIT_FAILURE);
		fill_stack(stacks->a, argv, argc);
		executing_instructions(stacks);
		if (is_sorted(stacks->a->head) && stacks->b->size == 0)
			write(STDOUT_FILENO, "OK\n", 3);
		else
			write(STDOUT_FILENO, "KO\n", 3);
	}
	return (0);
}