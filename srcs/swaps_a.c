/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swaps_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 16:57:14 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 18:55:03 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sa(t_stack *node)
{
	int	temp;

	if (node == NULL || node->next == NULL)
		return ;
	temp = node->next->value;
	node->next->value = node->value;
	node->value = temp;
	ft_putstr_fd("sa\n", 1);
	return ;
}

void	sb(t_stack *node)
{
	int	temp;

	if (node == NULL || node->next == NULL)
		return ;
	temp = node->next->value;
	node->next->value = node->value;
	node->value = temp;
	ft_putstr_fd("sb\n", 1);
	return ;
}
