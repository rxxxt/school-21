#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "stack.h"

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}			t_stacks;

void		processing(char *line, t_stacks *stacks);
void		executing_instructions(t_stacks *stacks);

#endif
