/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils_b.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 17:02:12 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 19:08:51 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	stackclear(t_stack **node, t_data *data, char *stack)
{
	data->i = 0;
	if (*node != NULL)
	{
		if (ft_strncmp("a", stack, 1) == 0)
		{
			while (data->i < data->a_count)
			{
				data->temp = (*node)->next;
				free(*node);
				*node = data->temp;
				data->i++;
			}
		}
		else if (ft_strncmp("b", stack, 1) == 0)
		{
			while (data->i < data->b_count)
			{
				data->temp = (*node)->next;
				free(*node);
				*node = data->temp;
				data->i++;
			}
		}
	}
}

void	add_to_stack(t_data *data, int value, char *stack)
{
	t_stack	*last;
	t_stack	*new;

	last = NULL;
	if (ft_strncmp("a", stack, 1) == 0)
	{
		last = stack_last(data->a, data, stack);
		data->a_count++;
		new = stack_new((long)value);
		new->previous = last;
		last->next = new;
		data->a->previous = new;
		new->next = data->a;
	}
	else if (ft_strncmp("b", stack, 1) == 0)
	{
		last = stack_last(data->b, data, stack);
		data->b_count++;
		new = stack_new(value);
		new->previous = last;
		last->next = new;
		data->b->previous = new;
		new->next = data->b;
	}
	return ;
}

static void	is_sorted_a(t_stack **node, t_data *data)
{
	(*node) = (*node)->next;
	data->i++;
}

static void	is_sorted_b(t_stack **node, t_data *data)
{
	(*node) = (*node)->next;
	data->i++;
}

int	is_sorted(t_stack *node, t_data *data, char *stack)
{
	data->i = 0;
	if (node != NULL)
	{
		if (ft_strncmp("a", stack, 1) == 0)
		{
			while (data->i < data->a_count - 1)
			{
				if (node->value > node->next->value)
					return (0);
				is_sorted_a(&node, data);
			}
		}
		else if (ft_strncmp("b", stack, 1) == 0)
		{
			while (data->i < data->b_count - 1)
			{
				if (node->value > node->next->value)
					return (0);
				is_sorted_b(&node, data);
			}
		}
	}
	else
		return (-1);
	return (1);
}
