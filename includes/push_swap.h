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
void	stackclear(t_stack **node);
void	stack_iter(t_stack *node, void(*f)(t_stack *));
void	add_to_stack(t_stack *node, int value);
int		is_sorted(t_stack *node);
int		is_smallest(t_stack *node, int number);
int		is_biggest(t_stack *node, int number);

//swaps
void	sa(t_stack *node);
void	sb(t_stack *node);
void	ss(t_stack *node_a, t_stack *node_b);
void	pa(t_stack **node_a, t_stack **node_b);
void	pb(t_stack **node_a, t_stack **node_b);
void	ra(t_stack *a, int rr);
void	rb(t_stack *b, int rr);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, int rrr);
void	rrb(t_stack *b, int rrr);
void	rrr(t_stack *a, t_stack *b);

//cases
void	swap_three(t_stack *a);
void	swap_five(t_stack *a, t_stack *b);

#endif