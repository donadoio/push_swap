/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_five_hundred.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 16:19:50 by idonado       #+#    #+#                 */
/*   Updated: 2021/09/01 22:48:54 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_five_hundred(t_data *data)
{
	data->max = find_maximum(data);
	data->one_eleventh = data->max / 11;
	data->first_rotate = 0;
	swap_chunk_loop(data, (data->one_eleventh * 10), data->max, 0);
	swap_back_large(data);
	swap_chunk_loop(data, (data->one_eleventh * 9), (data->one_eleventh * 10), 1);
	swap_back_large(data);
	swap_chunk_loop(data, (data->one_eleventh * 8), (data->one_eleventh * 9), 1);
	swap_back_large(data);
	swap_chunk_loop(data, (data->one_eleventh * 7), (data->one_eleventh * 8), 1);
	swap_back_large(data);
	swap_chunk_loop(data, (data->one_eleventh * 6), (data->one_eleventh * 7), 1);
	swap_back_large(data);
	swap_chunk_loop(data, (data->one_eleventh * 5), (data->one_eleventh * 6), 1);
	swap_back_large(data);
	swap_chunk_loop(data, (data->one_eleventh * 4), (data->one_eleventh * 5), 1);
	swap_back_large(data);
	swap_chunk_loop(data, (data->one_eleventh * 3), (data->one_eleventh * 4), 1);
	swap_back_large(data);
	swap_chunk_loop(data, (data->one_eleventh * 2), (data->one_eleventh * 3), 1);
	swap_back_large(data);
	swap_chunk_loop(data, data->one_eleventh, (data->one_eleventh * 2), 1);
	swap_back_large(data);
	swap_chunk_loop_zero(data, data->one_eleventh, 1);
	swap_back_large(data);
	return ;
}
