#include <push_swap.h>

void	pa_silent(t_stack **node_a, t_stack **node_b, t_data *data)
{
	t_stack *temp;
	t_stack	*temp2;

	if (*node_b == NULL || data->b_count == 0)
		return ;
	if (*node_a != NULL || data->a_count != 0)
	{
		temp = stack_new((*node_a)->value);
		temp->next = (*node_a)->next;
		temp->next->previous = temp;
		(*node_a)->value = (*node_b)->value;
		(*node_a)->next = temp;
		data->a_count++;
	}
	else
	{
		temp = stack_new((*node_b)->value);
		*node_a = temp;
		temp->previous = temp;
		temp->next = temp;
		data->a_count++;
	}
	if (data->b_count == 1)
	{
		free((*node_b));
		*node_b = NULL;
	}
	else if (data->b_count == 2)
	{
		temp2 = (*node_b);
		(*node_b) = (*node_b)->next;
		(*node_b)->next = (*node_b);
		(*node_b)->previous = (*node_b);
		free(temp2);
	}
	else
	{
		temp2 = (*node_b);
		(*node_b) = (*node_b)->next;
		(*node_b)->previous = temp2->previous;
		free(temp2);
	}
	data->b_count--;
	return ;
}

void	pb_silent(t_stack **node_a, t_stack **node_b, t_data *data)
{
	t_stack *temp;
	t_stack	*temp2;

	if (*node_a == NULL || data->a_count == 0)
		return ;
	if (*node_b != NULL || data->b_count != 0)
	{
		temp = stack_new((*node_b)->value);
		temp->next = (*node_b)->next;
		temp->next->previous = temp;
		(*node_b)->value = (*node_a)->value;
		(*node_b)->next = temp;
		data->b_count++;
	}
	else
	{
		temp = stack_new((*node_a)->value);
		*node_b = temp;
		temp->previous = temp;
		temp->next = temp;
		data->b_count++;
	}
	if (data->a_count == 1)
	{
		free((*node_a));
		*node_a = NULL;
	}
	else if (data->a_count == 2)
	{
		temp2 = (*node_a);
		(*node_a) = (*node_a)->next;
		(*node_a)->next = (*node_a);
		(*node_a)->previous = (*node_a);
		free(temp2);
	}
	else
	{
		temp2 = (*node_a);
		(*node_a) = (*node_a)->next;
		(*node_a)->previous = temp2->previous;
		free(temp2);
	}
	data->a_count--;
	return ;
}

void	ra_silent(t_stack *a, t_data *data)
{
	int temp;
	int i;

	if (a == NULL || a->next == NULL)
		return;
	i = 0;
	temp = a->value;
	while (i < data->a_count - 1)
	{
		a->value = a->next->value;
		a = a->next;
		i++;
	}
	a->value = temp;
	return ;
}