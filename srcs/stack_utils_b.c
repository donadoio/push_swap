#include <push_swap.h>

void	stackclear(t_stack *node)
{
	t_stack *temp;

	while (node->next != NULL)
	{
		temp = node->next;
		free(node);
		node = NULL;
		node = temp;
	}
	if (node != NULL)
		free(node);
}

//Must not be used to delete the last item or item inbetween unless it is handled.
//It is only safe to delete the first item of the list.
void	stackdelone(t_stack *node)
{
	free(node);
	node = NULL;
}

void	stack_iter(t_stack *node, void(*f)(t_stack *))
{
	(f)(node);
	return ;
}

void	add_to_stack(t_stack *node, int value)
{
	t_stack *last;
	t_stack	*new;

	last = stack_last(node);
	new = stack_new(value);
	last->next = new;
	return ;
}