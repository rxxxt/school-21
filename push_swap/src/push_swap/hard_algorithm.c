#include "../../includes/push_swap.h"
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

t_calc	*initialize_lists_for_calc(t_stacks *stacks)
{
	t_calc		*calc;
	t_action	*act;
	int			i;

	calc = malloc(sizeof(t_calc));
	calc->stack_a = NULL;
	i = stacks->b->size;
	while (i-- > 0)
	{
		act = malloc(sizeof(t_action));
		act->action = RA;
		act->count = 0;
		ft_lstadd_back(&calc->stack_a, ft_lstnew(act));
	}
	calc->stack_b = NULL;
	i = stacks->b->size;
	while (i-- > 0)
	{
		act = malloc(sizeof(t_action));
		act->action = RB;
		act->count = 0;
		ft_lstadd_back(&calc->stack_b, ft_lstnew(act));
	}
	return (calc);
}

t_calc	*calculation_of_actions(t_stacks *stacks)
{
	t_calc	*calc;
	t_node	*a;
	t_node	*b;

	calc = initialize_lists_for_calc(stacks);
	b = stacks->b->head;
	while (b)
	{
		a = stacks->a->head;
		while (a)
		{
			if (b->data < a->data)
				break ;
			else
				calc->stack_a->content
			a = a->next;
		}
		b = b->next;
	}
	return (calc);
}

void	actions(t_stacks *stacks)
{

}

void	hard_algorithm(t_stacks *stacks)
{
	t_calc	*calc;

	while (!is_sorted(stacks->a->head) && stacks->a->size > 3)
		push_b(stacks);
	if (stacks->a->size == 3 && !is_sorted(stacks->a->head))
		easy_algorithm(stacks);
	while (stacks->b->size)
	{
		calc = calculation_of_actions(stacks);
		actions(stacks);
	}
	print(stacks);
}