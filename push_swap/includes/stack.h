/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 01:09:28 by tredfort          #+#    #+#             */
/*   Updated: 2021/04/20 01:09:29 by tredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# define STACK_SIZE (1000)

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}			t_stack;

t_stack		*initialize_stack(void);
t_stack		*copy_stack(t_stack *stack);
t_node		*new_node(int x);
int			pop(t_stack *stack);
int			pop_back(t_stack *stack);
int			correct_number(char *str);
int			is_sorted(t_node *head);
int			there_are_duplicates(t_stack *stack);
void		fill_stack(t_stack *stack, char **argv, int count);
void		sorting_the_list(t_stack *stack);
void		free_stack(t_stack *stack);
void		ft_exit(void);
void		push(t_stack *stack, int x);
void		push_a_pop_b(t_stack *a, t_stack *b);
void		push_b_pop_a(t_stack *a, t_stack *b);
void		swap(t_stack *stack);
void		push_back(t_stack *stack, int x);
void		swap_a_and_b(t_stack *stack_a, t_stack *stack_b);
void		rotate(t_stack *stack);
void		rotate_a_and_b(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate(t_stack *stack);
void		reverse_rotate_a_and_b(t_stack *stack_a, t_stack *stack_b);

#endif