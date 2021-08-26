/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_hundred.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 19:13:29 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 17:17:49 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	swap_back_hundred(t_data *data)
{
	swap_back_loop(data);
	swap_back_loop(data);
	swap_back_loop(data);
	swap_back_loop(data);
	return ;
}

void	swap_hundred(t_data *data)
{
	data->max = find_maximum(data);
	data->one_fourth = data->max / 4;
	data->chunk_count = 0;
	data->chunks = NULL;
	swap_chunk_loop_zero(data, data->one_fourth);
	swap_chunk_loop(data, data->one_fourth, (data->one_fourth * 2));
	swap_chunk_loop(data, (data->one_fourth * 2), (data->one_fourth * 3));
	swap_chunk_loop(data, (data->one_fourth * 3), (data->max));
	swap_back_hundred(data);
	return ;
}
