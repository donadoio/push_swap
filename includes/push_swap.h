#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <libft.h>
//for testing
# include <stdio.h>

typedef	struct 	s_stack
{
	int				value;
	struct	s_stack	*previous;
	struct	s_stack	*next;
}				t_stack;

typedef	struct	s_data
{
	t_stack		*a;
	t_stack		*b;
	int			b_count;
	int			a_count;
}				t_data;

//temp functions for testing
void	print_list(t_stack *node, t_data *data, char *stack);


t_stack	*stack_new(int	number);
t_stack	*stack_last(t_stack *node, t_data *data, char *stack);
void	stackclear(t_stack **node, t_data *data, char *stack);
void	add_to_stack(t_data *data, int value, char *stack);
int		is_sorted(t_stack *node, t_data *data, char *stack);
int		is_smallest(t_stack *node, int number, t_data *data, char *stack);
int		is_biggest(t_stack *node, int number, t_data *data, char *stack);

//swaps
void	sa(t_stack *node);
void	sb(t_stack *node);
void	ss(t_stack *node_a, t_stack *node_b);
void	pa(t_stack **node_a, t_stack **node_b, t_data *data);
void	pb(t_stack **node_a, t_stack **node_b, t_data *data);
void	ra(t_stack *a, int rr, t_data *data);
void	rb(t_stack *b, int rr, t_data *data);
void	rr(t_stack *a, t_stack *b, t_data *data);
void	rra(t_stack *a, int rrr, t_data *data);
void	rrb(t_stack *b, int rrr, t_data *data);
void	rrr(t_stack *a, t_stack *b, t_data *data);

//cases
void	swap_three(t_data *data);
void	swap_four(t_data *data);
void	swap_five(t_data *data);
void	swap_six(t_data *data);

#endif