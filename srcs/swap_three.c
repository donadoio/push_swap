/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 17:04:59 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 17:05:37 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_three(t_data *data)
{
	if (data->a->value > data->a->next->value && \
	data->a->next->value < data->a->next->next->value \
	&& data->a->next->next->value > data->a->value)
	{
		sa(data->a);
		stackclear(&data->a, data, "a");
		exit(0);
	}
	else if (data->a->value > data->a->next->value \
	&& data->a->next->value > data->a->next->next->value \
	&& data->a->next->next->value < data->a->value)
	{
		sa(data->a);
		rra(data->a, 0, data);
		stackclear(&data->a, data, "a");
		exit(0);
	}
	else if (data->a->value > data->a->next->value \
	&& data->a->next->value < data->a->next->next->value && \
	data->a->next->next->value < data->a->value)
	{
		ra(data->a, 0, data);
		stackclear(&data->a, data, "a");
		exit(0);
	}
	else if (data->a->value < data->a->next->value \
	&& data->a->next->value > data->a->next->next->value && \
	data->a->next->next->value > data->a->value)
	{
		sa(data->a);
		ra(data->a, 0, data);
		stackclear(&data->a, data, "a");
		exit(0);
	}
	else if (data->a->value < data->a->next->value \
	&& data->a->next->value > data->a->next->next->value && \
	data->a->next->next->value < data->a->value)
	{
		rra(data->a, 0, data);
		stackclear(&data->a, data, "a");
		exit (0);
	}
}
