#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define R (1)
# define RR (2)

# include "../libft/libft.h"
# include "stack.h"

typedef struct s_calc
{
	int	action_a;
	int	count_a;
	int	action_b;
	int	count_b;
}			t_calc;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	t_calc	calc;
}			t_stacks;

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
t_calc		initialize_calc(void);
void		sorting_the_stack(t_stacks *stacks);
void		easy_algorithm(t_stacks *stacks);
void		normal_algorithm(t_stacks *stacks);
void		hard_algorithm(t_stacks *stacks);
int			get_last_data(t_stack *stack);
int			max_data(t_node *node);
void		optimization(t_stacks *stacks, t_calc calc);
void		adjustment(t_stacks *stacks);
void		last_adjustment(t_stacks *stacks);

#endif