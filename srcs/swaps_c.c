#include <push_swap.h>

void	rra(t_stack *a, int rrr, t_data *data)
{
	int last;
	int	current;
	int	temp;
	int i;

	if (a == NULL || a->next == NULL || data->a_count == 0)
		return;

	last = a->previous->value;
	temp = a->value;
	a->value = last;
	i = 1;
	a = a->next;
	while (i < data->a_count)
	{
		current = a->value;
		a->value = temp;
		a = a->next;
		temp = current;
		i++;
	}
	if (rrr == 0)
		ft_putstr_fd("rra\n", 1);
	return ;
}

void	rrb(t_stack *b, int rrr, t_data *data)
{
	int last;
	int	current;
	int	temp;
	int i;

	if (b == NULL || b->next == NULL || data->b_count == 0)
		return;
	last = b->previous->value;
	temp = b->value;
	b->value = last;
	b = b->next;
	i = 1;
	while (i < data->b_count)
	{
		current = b->value;
		b->value = temp;
		b = b->next;
		temp = current;
		i++;
	}
	if (rrr == 0)
		ft_putstr_fd("rrb\n", 1);
	return ;
}

void	rrr(t_stack *a, t_stack *b, t_data *data)
{
	rra(a, 1, data);
	rrb(b, 1, data);
	if (data->a_count != 0 || data->b_count != 0)
		ft_putstr_fd("rrr\n", 1);
	return ;
}