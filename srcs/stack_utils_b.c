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
