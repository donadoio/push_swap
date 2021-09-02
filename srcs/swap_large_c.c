/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_large_c.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/02 14:26:13 by idonado       #+#    #+#                 */
/*   Updated: 2021/09/02 14:37:03 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

static void	smart_rb_b(t_data *data)
{
	if (data->rb_count < data->rrb_count)
	{
		while (first_is_biggest(data) != 1)
			rb(data->b, 0, data);
	}
	else
	{
		while (first_is_biggest(data) != 1)
			rrb(data->b, 0, data);
	}
	return ;
}

void	smart_rb(t_data *data)
{
	data->rb_count = 0;
	data->rrb_count = 0;
	data->temp = data->b;
	while (smart_first_is_biggest(data, data->temp->value) != 1)
	{
		data->rb_count++;
		data->temp = data->temp->next;
	}
	data->temp = data->b;
	while (smart_first_is_biggest(data, data->temp->value) != 1)
	{
		data->rrb_count++;
		data->temp = data->temp->previous;
	}
	smart_rb_b(data);
	return ;
}

static void	smart_ra_b(t_data *data, long from, long til)
{
	while (data->trigger == 0)
	{
		if (data->temp->value > from && data->temp->value <= til)
			data->trigger = 1;
		data->temp = data->temp->previous;
		data->rra_count++;
	}
	data->rra_count--;
	if (data->ra_count < data->rra_count)
	{
		while (data->ra_count != 0)
		{
			ra(data->a, 0, data);
			data->ra_count--;
		}
	}
	else
	{
		while (data->rra_count != 0)
		{
			rra(data->a, 0, data);
			data->rra_count--;
		}
	}
	return ;
}

void	smart_ra(t_data *data, long from, long til)
{
	data->ra_count = 0;
	data->rra_count = 0;
	data->trigger = 0;
	data->temp = data->a;
	while (data->trigger == 0)
	{
		if (data->temp->value > from && data->temp->value <= til)
			data->trigger = 1;
		data->temp = data->temp->next;
		data->ra_count++;
	}
	data->ra_count--;
	data->temp = data->a;
	data->trigger = 0;
	smart_ra_b(data, from, til);
	return ;
}
