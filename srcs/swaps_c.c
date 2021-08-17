#include <push_swap.h>

void	rra(t_stack *a, int rrr)
{
	int last;
	int	current;
	int	temp;

	if (a == NULL || a->next == NULL)
		return;
	last = (stack_last(a))->value;
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

void	rrb(t_stack *b, int rrr)
{
	int last;
	int	current;
	int	temp;

	if (b == NULL || b->next == NULL)
		return;
	last = (stack_last(b))->value;
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

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 1);
	rrb(b, 1);
	ft_putstr_fd("rrr\n", 1);
	return ;
}