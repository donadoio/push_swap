#include <push_swap.h>

void	sa(t_stack *node)
{
	int temp;

	if (node == NULL || node->next == NULL)
		return ;
	temp = node->next->value;
	node->next->value = node->value;
	node->value = temp;
	ft_putstr_fd("sa\n", 1);
	return ;
}

void	sb(t_stack *node)
{
	int temp;

	if (node == NULL || node->next == NULL)
		return ;
	temp = node->next->value;
	node->next->value = node->value;
	node->value = temp;
	ft_putstr_fd("sb\n", 1);
	return ;
}

void	ss(t_stack *node_a, t_stack *node_b)
{
	sa(node_a);
	sb(node_b);
	ft_putstr_fd("ss\n", 1);
	return ;
}

void	pa(t_stack *node_a, t_stack *node_b)
{
	t_stack *temp;
	t_stack *temp2;

	if (node_b == NULL)
		return ;
	temp = stack_new(node_a->value);
	temp->next = node_a->next;
	node_a->value = node_b->value;
	node_a->next = temp;
	temp2 = node_b;
	node_b = node_b->next;
	stackdelone(temp2);
	return ;
}