#include "../../includes/checker.h"

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
		else
			write(1, "          |", 11);
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

void	processing(char *line, t_stacks *stacks)
{
	if (!ft_strcmp(line, "sa") && !line[2])
		swap(stacks->a);
	else if (!ft_strcmp(line, "sb") && !line[2])
		swap(stacks->b);
	else if (!ft_strcmp(line, "ss") && !line[2])
		swap_a_and_b(stacks->a, stacks->b);
	else if (!ft_strcmp(line, "pa") && !line[2])
		push_a(stacks->a, stacks->b);
	else if (!ft_strcmp(line, "pb") && !line[2])
		push_b(stacks->a, stacks->b);
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

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc > 1)
	{
		stacks.a = initialize_stack();
		stacks.b = initialize_stack();
		fill_stack(stacks.a, argv, argc);
		executing_instructions(&stacks);
		if (is_sorted(stacks.a->head) && stacks.b->size == 0)
			write(STDOUT_FILENO, "OK\n", 3);
		else
			write(STDOUT_FILENO, "KO\n", 3);
	}
	return (0);
}