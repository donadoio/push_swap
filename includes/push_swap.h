#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>

typedef	struct 	s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

t_stack	*stack_new(int	number);
t_stack	*stack_last(t_stack *stack);
void	stack_add_front(t_stack **list, t_stack *new);
void	stack_add_back(t_stack	**list, t_stack *new);
int		stack_size(t_stack	*stack);
void	stackdelone(t_stack *node);
void	stackclear(t_stack *node);


#endif