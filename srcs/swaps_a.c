/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swaps_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 16:57:14 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 17:07:46 by idonado       ########   odam.nl         */
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

void	pa(t_stack **node_a, t_stack **node_b, t_data *data)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (*node_b == NULL || data->b_count == 0)
		return ;
	if (*node_a != NULL || data->a_count != 0)
	{
		temp = stack_new((*node_a)->value);
		temp->next = (*node_a)->next;
		temp->next->previous = temp;
		(*node_a)->value = (*node_b)->value;
		(*node_a)->next = temp;
		data->a_count++;
	}
	else
	{
		temp = stack_new((*node_b)->value);
		*node_a = temp;
		temp->previous = temp;
		temp->next = temp;
		data->a_count++;
	}
	if (data->b_count == 1)
	{
		free((*node_b));
		*node_b = NULL;
	}
	else if (data->b_count == 2)
	{
		temp2 = (*node_b);
		(*node_b) = (*node_b)->next;
		(*node_b)->next = (*node_b);
		(*node_b)->previous = (*node_b);
		free(temp2);
	}
	else
	{
		temp2 = (*node_b);
		(*node_b) = (*node_b)->next;
		(*node_b)->previous = temp2->previous;
		free(temp2);
	}
	data->b_count--;
	ft_putstr_fd("pa\n", 1);
	return ;
}

void	pb(t_stack **node_a, t_stack **node_b, t_data *data)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (*node_a == NULL || data->a_count == 0)
		return ;
	if (*node_b != NULL || data->b_count != 0)
	{
		temp = stack_new((*node_b)->value);
		temp->next = (*node_b)->next;
		temp->next->previous = temp;
		(*node_b)->value = (*node_a)->value;
		(*node_b)->next = temp;
		data->b_count++;
	}
	else
	{
		temp = stack_new((*node_a)->value);
		*node_b = temp;
		temp->previous = temp;
		temp->next = temp;
		data->b_count++;
	}
	if (data->a_count == 1)
	{
		free((*node_a));
		*node_a = NULL;
	}
	else if (data->a_count == 2)
	{
		temp2 = (*node_a);
		(*node_a) = (*node_a)->next;
		(*node_a)->next = (*node_a);
		(*node_a)->previous = (*node_a);
		free(temp2);
	}
	else
	{
		temp2 = (*node_a);
		(*node_a) = (*node_a)->next;
		(*node_a)->previous = temp2->previous;
		free(temp2);
	}
	data->a_count--;
	ft_putstr_fd("pb\n", 1);
	return ;
}
