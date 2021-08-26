/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_large_c.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 16:35:52 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 17:18:57 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_chunks	*get_last_chunk(t_data *data)
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

void	add_chunk(t_chunks	**chunks, int amount, t_data *data)
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
