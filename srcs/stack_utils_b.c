#include <push_swap.h>

void	stackclear(t_stack **node, t_data *data, char *stack)
{
	t_stack *temp;
	int i;

	i = 0;
	if (*node != NULL)
	{
		if (ft_strncmp("a", stack, 1) == 0)
			while (i < data->a_count)
			{
				temp = (*node)->next;
				free(*node);
				*node = temp;
				i++;
			}
		else if (ft_strncmp("b", stack, 1) == 0)
			while (i < data->b_count)
			{
				temp = (*node)->next;
				free(*node);
				*node = temp;
				i++;
			}
	}
}

void	add_to_stack(t_data *data, int value, char *stack)
{
	t_stack *last;
	t_stack	*new;

	last = NULL;
	if (ft_strncmp("a", stack, 1) == 0)
	{
		last = stack_last(data->a, data, stack);
		data->a_count++;
		new = stack_new(value);
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

int		is_sorted(t_stack *node, t_data *data, char *stack)
{
	int i;

	i = 0;
	if (node != NULL)
	{
		if (ft_strncmp("a", stack, 1) == 0)
			while (i < data->a_count - 1)
			{
				if (node->value > node->next->value)
					return (0);
				node = node->next;
				i++;
			}
		else if (ft_strncmp("b", stack, 1) == 0)
			while (i < data->b_count - 1)
			{
				if (node->value > node->next->value)
					return (0);
				node = node->next;
				i++;
			}
	}
	else
		return (-1);
	return (1);
}
