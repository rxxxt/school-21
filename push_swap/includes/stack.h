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
#define STACK_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# define STACK_SIZE (1000)

typedef struct	s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct	s_stack
{
	t_node	*head;
	int		size;
}			t_stack;

typedef struct	s_stacks
{
	t_stack	*a;
	t_stack	*b;
}			t_stacks;

int			pop(t_stack *stack);
int			pop_back(t_stack *stack);
void		push(t_stack *stack, int x);
void		push_back(t_stack *stack, int x);
t_node		*ft_nodenew(int x);
t_stacks	*initialize_stacks(void);
void		processing(char *line, t_stacks *stacks);
void		ft_exit(void);

/*
 * 		Operations
 * */
void		processing(char *line, t_stacks *stacks);
void		swap_a(t_stacks *stacks);
void		swap_b(t_stacks *stacks);
void		swap_a_and_b(t_stacks *stacks);
void		push_a(t_stacks *stacks);
void		push_b(t_stacks *stacks);
void		rotate_a(t_stacks *stacks);
void		rotate_b(t_stacks *stacks);
void		rotate_a_and_b(t_stacks *stacks);
void		reverse_rotate_a(t_stacks *stacks);
void		reverse_rotate_b(t_stacks *stacks);
void		reverse_rotate_a_and_b(t_stacks *stacks);



#endif
