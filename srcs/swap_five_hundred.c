/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_five_hundred.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 16:19:50 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 17:17:41 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	swap_back_five_hundred(t_data *data)
{
	swap_back_loop(data);
	swap_back_loop(data);
	swap_back_loop(data);
	swap_back_loop(data);
	swap_back_loop(data);
	swap_back_loop(data);
	swap_back_loop(data);
	swap_back_loop(data);
	swap_back_loop(data);
	swap_back_loop(data);
	swap_back_loop(data);
	return ;
}

void	swap_five_hundred(t_data *data)
{
	data->max = find_maximum(data);
	data->one_eleventh = data->max / 11;
	data->chunk_count = 0;
	data->chunks = NULL;
	swap_chunk_loop_zero(data, data->one_eleventh);
	swap_chunk_loop(data, data->one_eleventh, (data->one_eleventh * 2));
	swap_chunk_loop(data, (data->one_eleventh * 2), (data->one_eleventh * 3));
	swap_chunk_loop(data, (data->one_eleventh * 3), (data->one_eleventh * 4));
	swap_chunk_loop(data, (data->one_eleventh * 4), (data->one_eleventh * 5));
	swap_chunk_loop(data, (data->one_eleventh * 5), (data->one_eleventh * 6));
	swap_chunk_loop(data, (data->one_eleventh * 6), (data->one_eleventh * 7));
	swap_chunk_loop(data, (data->one_eleventh * 7), (data->one_eleventh * 8));
	swap_chunk_loop(data, (data->one_eleventh * 8), (data->one_eleventh * 9));
	swap_chunk_loop(data, (data->one_eleventh * 9), (data->one_eleventh * 10));
	swap_chunk_loop(data, (data->one_eleventh * 10), data->max);
	swap_back_five_hundred(data);
	return ;
}
