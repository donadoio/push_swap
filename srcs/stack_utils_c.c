/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils_c.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 16:59:34 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 19:10:25 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_smallest(t_stack *node, int number, t_data *data, char *stack)
{
	int	i;

	i = 0;
	if (ft_strncmp("a", stack, 1) == 0)
	{
		while (i < data->a_count)
		{
			if (number > node->value)
				return (0);
			node = node->next;
			i++;
		}
	}
	else if (ft_strncmp("b", stack, 1) == 0)
	{
		while (i < data->b_count)
		{
			if (number > node->value)
				return (0);
			node = node->next;
			i++;
		}
	}
	return (1);
}

int	is_biggest(t_stack *node, int number, t_data *data, char *stack)
{
	int	i;

	i = 0;
	if (ft_strncmp("a", stack, 1) == 0)
	{
		while (i < data->a_count)
		{
			if (number < node->value)
				return (0);
			node = node->next;
			i++;
		}
	}
	else if (ft_strncmp("b", stack, 1) == 0)
	{
		while (i < data->b_count)
		{
			if (number < node->value)
				return (0);
			node = node->next;
			i++;
		}
	}
	return (1);
}

t_stack	*stack_new(long	number)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->value = number;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

int	find_minimum(t_data *data)
{
	int		i;
	t_stack	*temp;
	long	least;

	i = 0;
	least = 0;
	temp = data->a;
	while (i < data->a_count)
	{
		if (temp->value < least)
			least = temp->value;
		i++;
		temp = temp->next;
	}
	return (least);
}

void	add_least(t_data *data, long least)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = data->a;
	while (i < data->a_count)
	{
		temp->value = temp->value + least;
		temp = temp->next;
		i++;
	}
	return ;
}
