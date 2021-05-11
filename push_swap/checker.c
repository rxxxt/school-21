/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:59:28 by tredfort          #+#    #+#             */
/*   Updated: 2021/04/19 20:59:31 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stacks 	*initialize_stacks(void)
{
	t_stacks	*stack;

	stack = malloc(sizeof(t_stacks));
	if (!stack)
		return (NULL);
	stack->a = malloc(sizeof(t_stack));
	if (!stack->a)
		return (NULL);
	stack->b = malloc(sizeof(t_stack));
	if (!stack->b)
		return (NULL);
	(stack->a)->head = NULL;
	(stack->a)->size = 0;
	(stack->b)->head = NULL;
	(stack->b)->size = 0;
	return (stack);
}

void	fill_stack(t_stack  *stack, char **argv, int count)
{
	int		x;

	while (count > 0)
	{
		if ()
		x =
		push(stack, )
		count--;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stack;
	int			error;

	if (argc > 1)
	{
		error = 0;
		stack = initialize_stacks();
		if (!stack)
			exit(1);
		fill_stack(stack->a, argv, argc, &error);
		executing_instructions(stack->a, stack->b, &error);
		if (is_sorted(stack->a) && (stack->b)->size == 0)
			write(STDOUT_FILENO, "OK\n", 3);
		else
			write(STDOUT_FILENO, "KO\n", 3);
	}
	return (0);
}
