#include <push_swap.h>

void	stackclear(t_stack *node)
{
	t_stack *temp;

	while (node->next != NULL)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}
// below not working??
void	stackdelone(t_stack *node)
{
	free(node);
	node = NULL;
}