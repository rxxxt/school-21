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

#include "../../includes/push_swap.h"

int	correct_number(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	fill_stack(t_stack *stack, char **argv, int count)
{
	long nb;

	while (--count > 0)
	{
		nb = ft_atol(argv[count]);
		if (!correct_number(argv[count]) || nb > INT32_MAX || nb < INT32_MIN)
			ft_exit();
		push(stack, (int)nb);
	}
}

void	print_stack(t_node *head)
{
	while (head)
	{
		ft_putnbr_fd(head->data, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		head = head->next;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stack;

	if (argc > 1)
	{
		stack = initialize_stacks();
		if (!stack)
			exit(1);
		fill_stack(stack->a, argv, argc);
//		print_stack(stack->a->head);
//		executing_instructions(stack->a, stack->b);
//		if (is_sorted(stack->a) && stack->b->size == 0)
//			write(STDOUT_FILENO, "OK\n", 3);
//		else
//			write(STDOUT_FILENO, "KO\n", 3);
	}
	return (0);
}





