/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 17:19:29 by idonado       #+#    #+#                 */
/*   Updated: 2021/09/02 13:23:15 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <libft.h>

typedef struct s_dup_check
{
	int		i;
	int		j;
	size_t	len1;
	size_t	len2;
	size_t	len3;
}				t_dup_check;
typedef struct s_stack
{
	long			value;
	struct s_stack	*previous;
	struct s_stack	*next;
}				t_stack;
typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*temp;
	int			i;
	int			b_count;
	int			a_count;
	long		max;
	long		one_fourth;
	long		one_eleventh;
	int			amount;
	int			rrbs;
	int			moves;
	int			amount_copy;
	int			first_rotate;
	long		lowest_sorted;
}				t_data;
int			num_check(char **argv, int args);
int			dup_check(char **argv, int args);
int			int_check(char **argv, int args);
t_stack		*sub_malloc_protect(t_stack *stack, t_data *data);
void		add_least(t_data *data, long least);
int			find_minimum(t_data *data);
t_stack		*stack_new(long	number, t_data *data);
t_stack		*stack_last(t_stack *node, t_data *data, char *stack);
void		stackclear(t_stack **node, t_data *data, char *stack);
void		add_to_stack(t_data *data, int value, char *stack);
int			is_sorted(t_stack *node, t_data *data, char *stack);
int			is_smallest(t_stack *node, int number, t_data *data, char *stack);
int			is_biggest(t_stack *node, int number, t_data *data, char *stack);
void		swap_back_large(t_data *data);
void		swap_chunk_loop_zero(t_data *data, long til, int first_rotate);
void		swap_chunk_loop(t_data *data, long from, long til, int first_rotate);
int			inbetween_amount(t_data *data, int min, int max);
int			inbetween_amount_zero(t_data *data, int max);
long		find_maximum(t_data *data);
int			first_is_biggest(t_data *data);
int			last_is_biggest(t_data *data);

//swaps
void		sa(t_stack *node);
void		sb(t_stack *node);
void		ss(t_stack *node_a, t_stack *node_b);
void		pa(t_stack **node_a, t_stack **node_b, t_data *data);
void		pb(t_stack **node_a, t_stack **node_b, t_data *data);
void		ra(t_stack *a, int rr, t_data *data);
void		rb(t_stack *b, int rr, t_data *data);
void		rr(t_stack *a, t_stack *b, t_data *data);
void		rra(t_stack *a, int rrr, t_data *data);
void		rrb(t_stack *b, int rrr, t_data *data);
void		rrr(t_stack *a, t_stack *b, t_data *data);
//silent swaps for sorting private stack
void		ra_silent(t_stack *a, t_data *data);
void		pb_silent(t_stack **node_a, t_stack **node_b, t_data *data);
void		pa_silent(t_stack **node_a, t_stack **node_b, t_data *data);
//cases
void		swap_three(t_data *data);
void		swap_four(t_data *data);
void		swap_five(t_data *data);
void		swap_hundred(t_data *data);
void		swap_five_hundred(t_data *data);

#endif