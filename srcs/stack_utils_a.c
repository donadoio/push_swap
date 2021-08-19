#include <push_swap.h>

t_stack	*stack_new(int	number)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->value = number;
	new->next = NULL;
	return (new);
}

t_stack	*stack_last(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int		stack_size(t_stack	*stack)
{
	int i;

	i = 0;
	if (stack != NULL)
	{
		i++;
		while (stack->next != NULL)
		{
			i++;
			stack = stack->next;
		}
	}
	return (i);
}