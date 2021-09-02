/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_large_a.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 17:09:58 by idonado       #+#    #+#                 */
/*   Updated: 2021/09/02 14:35:12 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reset_a(t_data *data)
{
	data->ra_count = 0;
	data->rra_count = 0;
	data->temp = data->a;
	while (data->temp->value != data->lowest_sorted)
	{
		data->ra_count++;
		data->temp = data->temp->next;
	}
	data->temp = data->a;
	while (data->temp->value != data->lowest_sorted)
	{
		data->rra_count++;
		data->temp = data->temp->previous;
	}
	if (data->ra_count < data->rra_count)
	{
		while (data->a->value != data->lowest_sorted)
			ra(data->a, 0, data);
	}
	else
	{
		while (data->a->value != data->lowest_sorted)
			rra(data->a, 0, data);
	}
	return ;
}

void	swap_back_large(t_data *data)
{
	if (data->first_rotate == 1)
		reset_a(data);
	while (data->b_count != 0)
	{
		if (data->b_count == 1)
			data->lowest_sorted = data->b->value;
		if (first_is_biggest(data) == 1)
			pa(&data->a, &data->b, data);
		else if (last_is_biggest(data) == 1)
		{
			rrb(data->b, 0, data);
			pa(&data->a, &data->b, data);
		}
		else
			smart_rb(data);
	}
	data->first_rotate = 1;
	return ;
}

void	swap_chunk_loop(t_data *data, long from, long til)
{
	data->amount = inbetween_amount(data, from, til);
	while (data->amount != 0)
	{
		if (data->a->value > from && data->a->value <= til)
		{
			pb(&data->a, &data->b, data);
			data->amount--;
		}
		else if (data->a->previous->value \
		> from && data->a->previous->value <= til)
		{
			rra(data->a, 0, data);
			pb(&data->a, &data->b, data);
			data->amount--;
		}
		else
			smart_ra(data, from, til);
	}
	return ;
}

void	swap_chunk_loop_zero(t_data *data, long til)
{
	data->amount = inbetween_amount_zero(data, til);
	while (data->amount != 0)
	{
		if (data->a->value >= 0 && data->a->value <= til)
		{
			pb(&data->a, &data->b, data);
			data->amount--;
		}
		else if (data->a->previous->value >= 0 \
		&& data->a->previous->value <= til)
		{
			rra(data->a, 0, data);
			pb(&data->a, &data->b, data);
			data->amount--;
		}
		else
			smart_ra(data, -1, til);
	}
	return ;
}

int	last_is_biggest(t_data *data)
{
	int		i;
	int		last;
	t_stack	*temp;

	temp = data->b;
	last = temp->previous->value;
	i = 0;
	while (i < data->b_count)
	{
		if (temp->value > last)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}
