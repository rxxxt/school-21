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

void	sorting_stack(t_stacks *stacks)
{
	while (!is_sorted(stacks->a->head) || stacks->b->size)
	{
		if (stacks->a->head && stacks->a->head->next
			&& stacks->a->head->data > stacks->a->head->next->data)
		{
			swap_a(stacks);
			write(1, "sa\n", 3);
		}
	}
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
		sorting_stack(stacks);
	}
	return (0);
}