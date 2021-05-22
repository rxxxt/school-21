#include "../../includes/push_swap.h"

static int	need_adjustment(t_node *a, t_node *b, int last)
{
	if (((a->data > b->data || last < b->data) && is_sorted(a))
		|| (b->data < a->data && b->data > last))
		return (0);
	return (1);
}

static int	in_the_right_place(t_node *a, t_node *b, int max)
{
	if ((a->data < b->data && b->data < a->next->data)
		|| (b->data < a->next->data && is_sorted(a->next))
		|| (b->data > a->data && b->data > max
			&& is_sorted(a->next)))
		return (1);
	return (0);
}

void	optimization(t_stacks *stacks, t_calc calc)
{
	int	count;

	count = stacks->a->size - calc.count_a;
	if (count < 0)
		count = 0;
	if (count < calc.count_a)
	{
		calc.action_a = RR;
		calc.count_a = count;
	}
	count = stacks->b->size - calc.count_b;
	if (count < 0)
		count = 0;
	if (count < calc.count_b)
	{
		calc.action_b = RR;
		calc.count_b = count;
	}
	if (!stacks->calc.action_a
		|| (calc.count_a + calc.count_b
			< stacks->calc.count_a + stacks->calc.count_b))
		stacks->calc = calc;
}

static void	calculations_for_adjustments(t_stacks *stacks, t_node *b,
										 int max, int last)
{
	t_node	*a;
	t_calc	calc;
	int		count;

	count = 0;
	while (b)
	{
		a = stacks->a->head;
		calc = initialize_calc();
		if (need_adjustment(a, b, last))
		{
			while (a->next)
			{
				calc.count_a++;
				if (in_the_right_place(a, b, max))
					break ;
				a = a->next;
			}
		}
		calc.count_b = count;
		optimization(stacks, calc);
		count++;
		b = b->next;
	}
}

void	normal_algorithm(t_stacks *stacks)
{
	int	limiter;

	limiter = 0.96 * max_data(stacks->a->head);
	while (stacks->a->size > 3 && !is_sorted(stacks->a->head))
	{
		if (stacks->a->head->data < limiter
			&& stacks->a->head->data > get_last_data(stacks->a))
			rotate_a(stacks);
		else
			push_b(stacks);
	}
	if (stacks->a->size == 3 && !is_sorted(stacks->a->head))
		easy_algorithm(stacks);
	while (stacks->b->size)
	{
		ft_bzero((void *)&stacks->calc, sizeof(stacks->calc));
		calculations_for_adjustments(stacks, stacks->b->head,
			max_data(stacks->a->head), get_last_data(stacks->a));
		adjustment(stacks);
		push_a(stacks);
		if (stacks->a->head->data > stacks->a->head->next->data
			&& stacks->a->head->data < stacks->a->head->next->next->data)
			swap_a(stacks);
	}
	last_adjustment(stacks);
}
