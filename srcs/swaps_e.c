/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swaps_e.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 16:57:14 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 19:59:56 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	pa_condition_a(t_stack **node_a, \
t_stack **node_b, t_data *data, t_stack **temp)
{
	(*temp) = stack_new((*node_a)->value, data);
	(*temp)->next = (*node_a)->next;
	(*temp)->next->previous = (*temp);
	(*node_a)->value = (*node_b)->value;
	(*node_a)->next = (*temp);
	data->a_count++;
	return ;
}

static void	pa_condition_b(t_stack **node_a, \
t_stack **node_b, t_data *data, t_stack **temp)
{
	(*temp) = stack_new((*node_b)->value, data);
	*node_a = (*temp);
	(*temp)->previous = (*temp);
	(*temp)->next = (*temp);
	data->a_count++;
	return ;
}

static void	pa_condition_c(t_stack **node_b, t_stack **temp2)
{
	(*temp2) = (*node_b);
	(*node_b) = (*node_b)->next;
	(*node_b)->next = (*node_b);
	(*node_b)->previous = (*node_b);
	free((*temp2));
	return ;
}

static void	pa_condition_d(t_stack **node_b, t_stack **temp2)
{
	(*temp2) = (*node_b);
	(*node_b) = (*node_b)->next;
	(*node_b)->previous = (*temp2)->previous;
	free((*temp2));
	return ;
}

void	pa(t_stack **node_a, t_stack **node_b, t_data *data)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (*node_b == NULL || data->b_count == 0)
		return ;
	if (*node_a != NULL || data->a_count != 0)
		pa_condition_a(node_a, node_b, data, &temp);
	else
		pa_condition_b(node_a, node_b, data, &temp);
	if (data->b_count == 1)
	{
		free((*node_b));
		*node_b = NULL;
	}
	else if (data->b_count == 2)
		pa_condition_c(node_b, &temp2);
	else
		pa_condition_d(node_b, &temp2);
	data->b_count--;
	ft_putstr_fd("pa\n", 1);
	return ;
}
