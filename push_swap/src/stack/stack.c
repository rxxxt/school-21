/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:49:10 by tredfort          #+#    #+#             */
/*   Updated: 2021/04/20 20:49:13 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

t_node	*ft_nodenew(int x)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->data = x;
	new->next = NULL;
	return (new);
}

void	push(t_stack *stack, int x)
{
	t_node	*new;

	if (stack->size == STACK_SIZE)
		write(STDERR_FILENO, "Error: stack overflow\n", 22);
	else
	{
		new = ft_nodenew(x);
		new->next = stack->head;
		stack->head = new;
		++stack->size;
	}
}

void	push_back(t_stack *stack, int x)
{
	t_node	*node;

	if (stack->size == STACK_SIZE)
		write(STDERR_FILENO, "Error: stack overflow\n", 22);
	else
	{
		node = stack->head;
		while (node->next)
			node = node->next;
		node->next = ft_nodenew(x);
		++stack->size;
	}
}

int	pop(t_stack *stack)
{
	t_node	*tmp;
	int		x;

	x = 0;
	if (!stack->size)
		write(STDERR_FILENO, "Error: stack underflow\n", 23);
	else
	{
		tmp = stack->head;
		x = tmp->data;
		stack->head = tmp->next;
		free(tmp);
		--stack->size;
	}
	return (x);
}

int	pop_back(t_stack *stack)
{
	t_node	*tmp;
	int		x;

	x = 0;
	if (!stack->size)
		write(STDERR_FILENO, "Error: stack underflow\n", 23);
	else
	{
		tmp = stack->head;
		while (tmp->next && tmp->next->next)
			tmp = tmp->next;
		x = tmp->next->data;
		free(tmp->next);
		tmp->next = NULL;
		--stack->size;
	}
	return (x);
}