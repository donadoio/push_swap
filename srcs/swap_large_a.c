/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_large_a.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 17:09:58 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 17:09:59 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_chunk_loop(t_data *data, long from, long til)
{
	data->amount = inbetween_amount(data, from, til);
	add_chunk(&data->chunks, data->amount, data);
	while (data->amount != 0)
	{
		if (data->a->value > from && data->a->value <= til)
		{
			pb(&data->a, &data->b, data);
			data->amount--;
		}
		else
			ra(data->a, 0, data);
	}
	return ;
}

void	swap_chunk_loop_zero(t_data *data, long til)
{
	data->amount = inbetween_amount_zero(data, til);
	add_chunk(&data->chunks, data->amount, data);
	while (data->amount != 0)
	{
		if (data->a->value >= 0 && data->a->value <= til)
		{
			pb(&data->a, &data->b, data);
			data->amount--;
		}
		else
			ra(data->a, 0, data);
	}
	return ;
}

void	swap_back_loop_if_a(t_data *data, t_chunks *last)
{
	if (first_is_biggest(data) == 1)
	{
		pa(&data->a, &data->b, data);
		last->amount--;
		data->moves++;
	}
	else
	{
		rb(data->b, 0, data);
		data->rrbs++;
		data->moves++;
	}
}

void	swap_back_loop_if_b(t_data *data, t_chunks *last)
{
	if (last->amount != 0 && data->moves == data->amount_copy)
	{
		while (data->rrbs != 0)
		{
			rrb(data->b, 0, data);
			data->rrbs--;
			if (first_is_biggest(data) == 1)
			{
				pa(&data->a, &data->b, data);
				last->amount--;
			}
		}
		data->moves = 0;
		data->amount_copy = last->amount;
	}
}

void	swap_back_loop(t_data *data)
{
	t_chunks	*last;

	last = get_last_chunk(data);
	data->rrbs = 0;
	data->moves = 0;
	data->amount_copy = last->amount;
	while (last->amount != 0)
	{
		swap_back_loop_if_a(data, last);
		swap_back_loop_if_b(data, last);
	}
	free(last);
	last = NULL;
	data->chunk_count--;
	return ;
}
