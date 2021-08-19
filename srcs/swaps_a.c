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

void	pa(t_stack **node_a, t_stack **node_b, t_data *data)
{
	t_stack *temp;
	t_stack *temp2;

	if (*node_b == NULL)
		return ;
	if (*node_a != NULL)
	{
		temp = stack_new((*node_a)->value);
		temp->next = (*node_a)->next;
		(*node_a)->value = (*node_b)->value;
		(*node_a)->next = temp;
	}
	else
	{
		temp = stack_new((*node_b)->value);
		(*node_a) = temp;
	}
	temp2 = (*node_b);
	(*node_b) = (*node_b)->next;
	free(temp2);
	temp2 = NULL;
	data->a_count++;
	data->b_count--;
	ft_putstr_fd("pa\n", 1);
	return ;
}

void	pb(t_stack **node_a, t_stack **node_b, t_data *data)
{
	t_stack *temp;
	t_stack *temp2;

	if (*node_a == NULL)
		return ;
	if (*node_b != NULL)
	{
		temp = stack_new((*node_b)->value);
		temp->next = (*node_b)->next;
		(*node_b)->value = (*node_a)->value;
		(*node_b)->next = temp;
	}
	else
	{
		temp = stack_new((*node_a)->value);
		(*node_b) = temp;
	}
	temp2 = (*node_a);
	(*node_a) = (*node_a)->next;
	free(temp2);
	temp2 = NULL;
	data->b_count++;
	data->a_count--;
	ft_putstr_fd("pb\n", 1);
	return ;
}