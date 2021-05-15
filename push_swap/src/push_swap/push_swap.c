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

void	hard_algorithm()
{

}

void	sorting_stack(t_stacks *stacks)
{
	if (stacks->a->size < 6)
		easy_algorithm();
	else
		hard_algorithm();



	while (!is_sorted(stacks->a->head) || stacks->b->size)
	{
		if (stacks->a->head && stacks->a->head->next
			&& stacks->a->head->data > stacks->a->head->next->data)
		{
			swap(stacks->a);
			write(1, "sa\n", 3);
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
		sorting_stack(&stacks);
	}
	return (0);
}