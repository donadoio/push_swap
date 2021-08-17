#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <libft.h>
//for testing
# include <stdio.h>

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
void	stack_iter(t_stack *node, void(*f)(t_stack *));
void	add_to_stack(t_stack *node, int value);

//swaps
void	sa(t_stack *node);
void	sb(t_stack *node);
void	ss(t_stack *node_a, t_stack *node_b);
void	pa(t_stack *node_a, t_stack *node_b);

#endif