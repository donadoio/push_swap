/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_large_a.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 17:09:58 by idonado       #+#    #+#                 */
/*   Updated: 2021/09/02 13:23:51 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	reset_a(t_data *data)
{
	int ra_count;
	int rra_count;
	t_stack *temp;

	ra_count = 0;
	rra_count = 0;
	temp = data->a;
	while (temp->value != data->lowest_sorted)
	{
		ra_count++;
		temp = temp->next;
	}
	temp = data->a;
	while (temp->value != data->lowest_sorted)
	{
		rra_count++;
		temp = temp->previous;
	}
	if (ra_count < rra_count)
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

static int	smart_first_is_biggest(t_data *data, int temp_value)
{
	int		i;
	long	first;
	t_stack	*temp;

	temp = data->b;
	first = temp_value;
	i = 0;
	while (i < data->b_count)
	{
		if (temp->value > first)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

static void	smart_rb(t_data *data)
{
	int	rb_counter;
	int	rrb_counter;
	t_stack	*temp;

	rb_counter = 0;
	rrb_counter = 0;
	temp = data->b;
	while (smart_first_is_biggest(data, temp->value) != 1)
	{
		rb_counter++;
		temp = temp->next;
	}
	temp = data->b;
	while (smart_first_is_biggest(data, temp->value) != 1)
	{
		rrb_counter++;
		temp = temp->previous;
	}
	if (rb_counter < rrb_counter)
	{
		while (first_is_biggest(data) != 1)
			rb(data->b, 0, data);
	}
	else
	{
		while (first_is_biggest(data) != 1)
			rrb(data->b, 0, data);
	}
	return;
}

//static void	smart_ra(t_data *data, long from, long til)
//{
//	return ;
//}

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

void	swap_chunk_loop(t_data *data, long from, long til, int first_rotate)
{
	data->amount = inbetween_amount(data, from, til);
	while (data->amount != 0)
	{
		if (data->a->value > from && data->a->value <= til)
		{
			pb(&data->a, &data->b, data);
			data->amount--;
		}
		else if (data->a->previous->value > from && data->a->previous->value <= til)
		{
			rra(data->a, 0, data);
			pb(&data->a, &data->b, data);
			data->amount--;
		}
		else
			if (first_rotate == 0)
				ra(data->a, 0, data);
			else if (first_rotate == 1)
				rra(data->a, 0, data);
	}
	return ;
}

void	swap_chunk_loop_zero(t_data *data, long til, int first_rotate)
{
	data->amount = inbetween_amount_zero(data, til);
	while (data->amount != 0)
	{
		if (data->a->value >= 0 && data->a->value <= til)
		{
			pb(&data->a, &data->b, data);
			data->amount--;
		}
		else if (data->a->previous->value >= 0 && data->a->previous->value <= til)
		{
			rra(data->a, 0, data);
			pb(&data->a, &data->b, data);
			data->amount--;
		}
		else
		{
			if (first_rotate == 0)
				ra(data->a, 0, data);
			else if (first_rotate == 1)
				rra(data->a, 0, data);
		}
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