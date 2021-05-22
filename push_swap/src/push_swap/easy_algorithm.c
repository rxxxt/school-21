#include "../../includes/push_swap.h"

void	easy_algorithm(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	first = stacks->a->head->data;
	second = stacks->a->head->next->data;
	third = stacks->a->head->next->next->data;
	if (first > second && first < third)
		swap_a(stacks);
	else if (first < second && first > third)
		reverse_rotate_a(stacks);
	else if (first > second && second < third)
		rotate_a(stacks);
	else if (first > second && second > third)
	{
		swap_a(stacks);
		reverse_rotate_a(stacks);
	}
	else if (first < second && second > third)
	{
		reverse_rotate_a(stacks);
		swap_a(stacks);
	}
}
