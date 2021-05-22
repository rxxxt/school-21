#include "../../includes/push_swap.h"

void	hard_algorithm(t_stacks *stacks)
{
	while (stacks->a->size > 3 && !is_sorted(stacks->a->head))
	{
		if (stacks->a->head->data > get_last_data(stacks->a))
			rotate_a(stacks);
		else
			push_b(stacks);
	}
	normal_algorithm(stacks);
}
