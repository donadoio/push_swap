/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swaps_d.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 16:57:14 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 18:53:54 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	pb_contition_a(t_stack **node_a, \
t_stack **node_b, t_data *data, t_stack **temp)
{
	(*temp) = stack_new((*node_b)->value);
	(*temp)->next = (*node_b)->next;
	(*temp)->next->previous = (*temp);
	(*node_b)->value = (*node_a)->value;
	(*node_b)->next = (*temp);
	data->b_count++;
}

static void	pb_contition_b(t_stack **node_a, \
t_stack **node_b, t_data *data, t_stack **temp)
{
	(*temp) = stack_new((*node_a)->value);
	*node_b = (*temp);
	(*temp)->previous = (*temp);
	(*temp)->next = (*temp);
	data->b_count++;
}

static void	pb_contition_c(t_stack **node_a, t_stack **temp2)
{
	(*temp2) = (*node_a);
	(*node_a) = (*node_a)->next;
	(*node_a)->next = (*node_a);
	(*node_a)->previous = (*node_a);
	free((*temp2));
}

static void	pb_contition_d(t_stack **node_a, t_stack **temp2)
{
	(*temp2) = (*node_a);
	(*node_a) = (*node_a)->next;
	(*node_a)->previous = (*temp2)->previous;
	free((*temp2));
}

void	pb(t_stack **node_a, t_stack **node_b, t_data *data)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (*node_a == NULL || data->a_count == 0)
		return ;
	if (*node_b != NULL || data->b_count != 0)
		pb_contition_a(node_a, node_b, data, &temp);
	else
		pb_contition_b(node_a, node_b, data, &temp);
	if (data->a_count == 1)
	{
		free((*node_a));
		*node_a = NULL;
	}
	else if (data->a_count == 2)
		pb_contition_c(node_a, &temp2);
	else
		pb_contition_d(node_a, &temp2);
	data->a_count--;
	ft_putstr_fd("pb\n", 1);
	return ;
}
