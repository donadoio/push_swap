/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 17:04:59 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 18:28:37 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	swap_three_condition_a(t_data *data)
{
	sa(data->a);
	stackclear(&data->a, data, "a");
	exit(0);
	return ;
}

static void	swap_three_condition_b(t_data *data)
{
	sa(data->a);
	rra(data->a, 0, data);
	stackclear(&data->a, data, "a");
	exit(0);
	return ;
}

static void	swap_three_condition_c(t_data *data)
{
	ra(data->a, 0, data);
	stackclear(&data->a, data, "a");
	exit(0);
	return ;
}

static void	swap_three_condition_d(t_data *data)
{
	sa(data->a);
	ra(data->a, 0, data);
	stackclear(&data->a, data, "a");
	exit(0);
	return ;
}

void	swap_three(t_data *data)
{
	if (data->a->value > data->a->next->value && \
	data->a->next->value < data->a->next->next->value \
	&& data->a->next->next->value > data->a->value)
		swap_three_condition_a(data);
	else if (data->a->value > data->a->next->value \
	&& data->a->next->value > data->a->next->next->value \
	&& data->a->next->next->value < data->a->value)
		swap_three_condition_b(data);
	else if (data->a->value > data->a->next->value \
	&& data->a->next->value < data->a->next->next->value && \
	data->a->next->next->value < data->a->value)
		swap_three_condition_c(data);
	else if (data->a->value < data->a->next->value \
	&& data->a->next->value > data->a->next->next->value && \
	data->a->next->next->value > data->a->value)
		swap_three_condition_d(data);
	else if (data->a->value < data->a->next->value \
	&& data->a->next->value > data->a->next->next->value && \
	data->a->next->next->value < data->a->value)
	{
		rra(data->a, 0, data);
		stackclear(&data->a, data, "a");
		exit (0);
	}
}
