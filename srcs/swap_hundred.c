/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_hundred.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 19:13:29 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/25 21:08:45 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int first_is_biggest(t_data *data)
{
	int i;
	int first;
	t_stack	*temp;

	temp = data->b;
	first = temp->value;
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


static long	find_maximum(t_data *data)
{
	int	i;
	t_stack	*temp;
	long	most;

	i = 0;
	most = 0;
	temp = data->a;
	while (i < data->a_count)
	{
		if (temp->value > most)
			most = temp->value;
		i++;
		temp = temp->next;
	}
	return (most);
}

static int	inbetween_amount_zero(t_data *data, int max)
{
	int i;
	int	amount;
	t_stack	*temp;

	i = 0;
	amount = 0;
	temp = data->a;
	while (i < data->a_count)
	{
		if (temp->value >= 0 && temp->value <= max)
			amount++;
		temp = temp->next;
		i++;
	}
	return (amount);
}

static int	inbetween_amount(t_data *data, int min, int max)
{
	int i;
	int	amount;
	t_stack	*temp;

	i = 0;
	amount = 0;
	temp = data->a;
	while (i < data->a_count)
	{
		if (temp->value > min && temp->value <= max)
			amount++;
		temp = temp->next;
		i++;
	}
	return (amount);
}

static	void	add_chunk(t_chunks	**chunks, int amount, t_data *data)
{
	t_chunks	*last;
	t_chunks	*temp;

	last = NULL;

	if (*chunks == NULL)
	{
		(*chunks) = malloc(sizeof(t_chunks));
		(*chunks)->amount = amount;
		(*chunks)->next = NULL;
		data->chunk_count++;
	}
	else
	{
		temp = *chunks;
		while (temp->next != NULL)
			temp = temp->next;
		last = malloc(sizeof(t_chunks));
		temp->next = last;
		last->amount = amount;
		last->next = NULL;
		data->chunk_count++;
	}
	return ;
}

static t_chunks	*get_last_chunk(t_data *data)
{
	t_chunks	*last;
	int			i;

	i = 0;
	last = data->chunks;
	while (i < data->chunk_count - 1)
	{
		last = last->next;
		i++;
	}
	last->next = NULL;
	return (last);
}

void	swap_hundred(t_data *data)
{
	long	max;
	long	one_fourth;
	int		amount;

	max = find_maximum(data);
	one_fourth = max / 4;
	data->chunk_count = 0;
	data->chunks = NULL;


	amount = inbetween_amount_zero(data, one_fourth);
	add_chunk(&data->chunks, amount, data);
	while (amount != 0)
	{
		if (data->a->value >= 0 && data->a->value <= one_fourth)
		{
			pb(&data->a, &data->b, data);
			amount--;
		}
		else
			ra(data->a, 0, data);
	}



	amount = inbetween_amount(data, one_fourth, one_fourth * 2);
	add_chunk(&data->chunks, amount, data);
	while (amount != 0)
	{
		if (data->a->value > one_fourth && data->a->value <= one_fourth * 2)
		{
			pb(&data->a, &data->b, data);
			amount--;
		}
		else
			ra(data->a, 0 , data);
	}


	amount = inbetween_amount(data, one_fourth * 2, one_fourth * 3);
	add_chunk(&data->chunks, amount, data);
	while (amount != 0)
	{
		if (data->a->value > one_fourth * 2 && data->a->value <= one_fourth * 3)
		{
			pb(&data->a, &data->b, data);
			amount--;
		}
		else
			ra(data->a, 0, data);

	}


	amount = inbetween_amount(data, one_fourth * 3, max);
	add_chunk(&data->chunks, amount, data);
	while (amount != 0)
	{
		if (data->a->value > one_fourth * 3 && data->a->value <= max)
		{
			pb(&data->a, &data->b, data);
			amount--;
		}
		else
			ra(data->a, 0, data);
	}



	// Begin sorting in stack B and pushing back to stack A
	t_chunks	*last = get_last_chunk(data);



	int rrbs = 0;
	int	moves;
	int	amountcpy;
	amountcpy = last->amount;
	moves = 0;
	while (last->amount != 0)
	{
		if (first_is_biggest(data) == 1)
		{
			pa(&data->a, &data->b, data);
			last->amount--;
			moves++;
		}
		else
		{
			rb(data->b, 0, data);
			rrbs++;
			moves++;
		}
		if (last->amount != 0 && moves == amountcpy)
		{
			while (rrbs != 0)
			{
				rrb(data->b, 0, data);
				rrbs--;
				if (first_is_biggest(data) == 1)
				{
					pa(&data->a, &data->b, data);
					last->amount--;
				}
			}
			moves = 0;
			amountcpy = last->amount;
		}
	}
	free(last);
	last = NULL;
	data->chunk_count--;

	last = get_last_chunk(data);
	rrbs = 0;
	moves = 0;
	amountcpy = last->amount;

	while (last->amount != 0)
	{
		if (first_is_biggest(data) == 1)
		{
			pa(&data->a, &data->b, data);
			last->amount--;
			moves++;
		}
		else
		{
			rb(data->b, 0, data);
			rrbs++;
			moves++;
		}
		if (last->amount != 0 && moves == amountcpy)
		{
			while (rrbs != 0)
			{
				rrb(data->b, 0, data);
				rrbs--;
				if (first_is_biggest(data) == 1)
				{
					pa(&data->a, &data->b, data);
					last->amount--;
				}
			}
			moves = 0;
			amountcpy = last->amount;
		}
	}
	free(last);
	last = NULL;
	data->chunk_count--;


	last = get_last_chunk(data);
	rrbs = 0;
	moves = 0;
	amountcpy = last->amount;

	while (last->amount != 0)
	{
		if (first_is_biggest(data) == 1)
		{
			pa(&data->a, &data->b, data);
			last->amount--;
			moves++;
		}
		else
		{
			rb(data->b, 0, data);
			rrbs++;
			moves++;
		}
		if (last->amount != 0 && moves == amountcpy)
		{
			while (rrbs != 0)
			{
				rrb(data->b, 0, data);
				rrbs--;
				if (first_is_biggest(data) == 1)
				{
					pa(&data->a, &data->b, data);
					last->amount--;
				}
			}
			moves = 0;
			amountcpy = last->amount;
		}
	}
	free(last);
	last = NULL;
	data->chunk_count--;


	last = get_last_chunk(data);
	rrbs = 0;
	moves = 0;
	amountcpy = last->amount;

	while (last->amount != 0)
	{
		if (first_is_biggest(data) == 1)
		{
			pa(&data->a, &data->b, data);
			last->amount--;
			moves++;
		}
		else
		{
			rb(data->b, 0, data);
			rrbs++;
			moves++;
		}
		if (last->amount != 0 && moves == amountcpy)
		{
			while (rrbs != 0)
			{
				rrb(data->b, 0, data);
				rrbs--;
				if (first_is_biggest(data) == 1)
				{
					pa(&data->a, &data->b, data);
					last->amount--;
				}
			}
			moves = 0;
			amountcpy = last->amount;
		}
	}
	free(last);
	last = NULL;
	data->chunk_count--;








	return ;
}