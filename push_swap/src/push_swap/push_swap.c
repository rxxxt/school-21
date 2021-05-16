#include "../../includes/push_swap.h"

void	sorting_stack(t_stacks *stacks)
{
	if (stacks->a->size < 4)
		easy_algorithm(stacks);
	else
		hard_algorithm(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc > 1)
	{
		stacks.a = initialize_stack();
		stacks.b = initialize_stack();
		fill_stack(stacks.a, argv, argc);
		if (!is_sorted(stacks.a->head))
			sorting_stack(&stacks);
	}
	return (0);
}
