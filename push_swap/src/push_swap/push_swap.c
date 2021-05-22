#include "../../includes/push_swap.h"

void	sorting_the_stack(t_stacks *stacks)
{
	if (stacks->a->size == 2)
		swap_a(stacks);
	else if (stacks->a->size == 3)
		easy_algorithm(stacks);
	else if (stacks->a->size < 6)
		normal_algorithm(stacks);
	else
		hard_algorithm(stacks);
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
		if (!is_sorted(stacks.a->head))
			sorting_the_stack(&stacks);
		free_stack(stacks.a);
		free_stack(stacks.b);
	}
	return (0);
}
