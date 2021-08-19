#include <push_swap.h>

void	rra(t_stack *a, int rrr, t_data *data)
{
	int last;
	int	current;
	int	temp;

	if (a == NULL || a->next == NULL)
		return;
	last = (stack_last(a, data, "a"))->value;
	temp = a->value;
	a->value = last;
	a = a->next;
	while (a->next != NULL)
	{
		current = a->value;
		a->value = temp;
		a = a->next;
		temp = current;
	}
	current = a->value;
	a->value = temp;
	temp = current;
	if (rrr == 0)
		ft_putstr_fd("rra\n", 1);
	return ;
}

void	rrb(t_stack *b, int rrr, t_data *data)
{
	int last;
	int	current;
	int	temp;

	if (b == NULL || b->next == NULL)
		return;
	last = (stack_last(b, data, "b"))->value;
	temp = b->value;
	b->value = last;
	b = b->next;
	while (b->next != NULL)
	{
		current = b->value;
		b->value = temp;
		b = b->next;
		temp = current;
	}
	current = b->value;
	b->value = temp;
	temp = current;
	if (rrr == 0)
		ft_putstr_fd("rrb\n", 1);
	return ;
}

void	rrr(t_stack *a, t_stack *b, t_data *data)
{
	rra(a, 1, data);
	rrb(b, 1, data);
	ft_putstr_fd("rrr\n", 1);
	return ;
}