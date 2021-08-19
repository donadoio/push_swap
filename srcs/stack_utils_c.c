#include <push_swap.h>

int	is_smallest(t_stack *node, int number, t_data *data, char *stack)
{
	int i;

	i = 0;
	if (ft_strncmp("a", stack, 1) == 0)
		while (i < data->a_count)
		{
			if (number > node->value)
				return (0);
			node = node->next;
			i++;
		}
	else if (ft_strncmp("b", stack, 1) == 0)
		while (i < data->b_count)
		{
			if (number > node->value)
				return (0);
			node = node->next;
			i++;
		}
	return (1);
}

int	is_biggest(t_stack *node, int number, t_data *data, char *stack)
{
	int i;

	i = 0;
	if (ft_strncmp("a", stack, 1) == 0)
		while (i < data->a_count)
		{
			if (number < node->value)
				return (0);
			node = node->next;
			i++;
		}
	else if (ft_strncmp("b", stack, 1) == 0)
		while (i < data->b_count)
		{
			if (number < node->value)
				return (0);
			node = node->next;
			i++;
		}
	return (1);
}