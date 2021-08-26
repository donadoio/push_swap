/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_large_b.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 16:33:33 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 17:14:35 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	first_is_biggest(t_data *data)
{
	int		i;
	int		first;
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

long	find_maximum(t_data *data)
{
	int		i;
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

int	inbetween_amount_zero(t_data *data, int max)
{
	int		i;
	int		amount;
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

int	inbetween_amount(t_data *data, int min, int max)
{
	int		i;
	int		amount;
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
