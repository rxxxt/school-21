#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SA (1)
# define SB (2)
# define SS (3)
# define RA (4)
# define RB (5)
# define RR (6)
# define RRA (7)
# define RRB (8)
# define RRR (9)

# include "../libft/libft.h"
# include "stack.h"

typedef struct s_action
{
	int	action;
	int	count;
}			t_action;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}			t_stacks;

typedef struct s_calc
{
	t_list	*stack_a;
	t_list	*stack_b;
}			t_calc;

void		push_a(t_stacks *stacks);
void		push_b(t_stacks *stacks);
void		reverse_rotate_a(t_stacks *stacks);
void		reverse_rotate_b(t_stacks *stacks);
void		reverse_rotate_a_b(t_stacks *stacks);
void		rotate_a(t_stacks *stacks);
void		rotate_b(t_stacks *stacks);
void		rotate_a_b(t_stacks *stacks);
void		swap_a(t_stacks *stacks);
void		swap_b(t_stacks *stacks);
void		swap_a_b(t_stacks *stacks);
void		easy_algorithm(t_stacks *stacks);
void		hard_algorithm(t_stacks *stacks);

#endif