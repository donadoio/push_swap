#include <push_swap.h>

t_stack	*stack_new(int	number)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->value = number;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

t_stack	*stack_last(t_stack *node, t_data *data, char *stack)
{
	int i;

	i = 0;
	if (ft_strncmp(stack, "a", 1) == 0)
		while (i < data->a_count - 1)
		{
			node = node->next;
			i++;
		}
	else if (ft_strncmp(stack, "b", 1) == 0)
		while (i < data->b_count - 1)
		{
			node = node->next;
			i++;
		}
	return (node);
}
