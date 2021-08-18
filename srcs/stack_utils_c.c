#include <push_swap.h>

int	is_smallest(t_stack *node, int number)
{
	while (node->next != NULL)
	{
		if (number > node->value)
			return (0);
		node = node->next;
	}
	if (number > node->value)
			return (0);
	return (1);
}

int	is_biggest(t_stack *node, int number)
{
	while (node->next != NULL)
	{
		if (number < node->value)
			return (0);
		node = node->next;
	}
	if (number < node->value)
			return (0);
	return (1);
}