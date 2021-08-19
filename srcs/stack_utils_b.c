#include <push_swap.h>

void	stackclear(t_stack **node)
{
	t_stack *temp;
	if (*node != NULL)
	{
		while ((*node)->next != NULL)
		{
			temp = (*node)->next;
			free(*node);
			*node = temp;
		}
	}
	if ((*node) != NULL)
	{
		free(*node);
		(*node) = NULL;
	}
}


void	stack_iter(t_stack *node, void(*f)(t_stack *))
{
	(f)(node);
	return ;
}

void	add_to_stack(t_data *data, int value, char *stack)
{
	t_stack *last;
	t_stack	*new;

	last = NULL;
	if (ft_strncmp("a", stack, 1) == 0)
	{
		last = stack_last(data->a);
		data->a_count++;
	}
	else if (ft_strncmp("b", stack, 1) == 0)
	{
		last = stack_last(data->b);
		data->b_count++;
	}
	new = stack_new(value);
	last->next = new;
	return ;
}

int		is_sorted(t_stack *node)
{
	if (node != NULL)
	{
		while (node->next != NULL)
		{
			if (node->value > node->next->value)
				return (0);
			node = node->next;
		}
	}
	else
		return (-1);
	return (1);
}
