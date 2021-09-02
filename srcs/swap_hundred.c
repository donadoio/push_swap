/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_hundred.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 19:13:29 by idonado       #+#    #+#                 */
/*   Updated: 2021/09/01 22:48:46 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_hundred(t_data *data)
{
	data->max = find_maximum(data);
	data->one_fourth = data->max / 4;
	data->first_rotate = 0;

	swap_chunk_loop(data, (data->one_fourth * 3), (data->max), 0);
	swap_back_large(data);
	swap_chunk_loop(data, (data->one_fourth * 2), (data->one_fourth * 3), 1);
	swap_back_large(data);
	swap_chunk_loop(data, data->one_fourth, (data->one_fourth * 2), 1);
	swap_back_large(data);
	swap_chunk_loop_zero(data, data->one_fourth, 1);
	swap_back_large(data);
	
	return ;
}
