#include <push_swap.h>

void	ra(t_stack *a, int rr)
{
	int temp;

	if (a == NULL || a->next == NULL)
		return;
	temp = a->value;
	while (a->next != NULL)
	{
		a->value = a->next->value;
		a = a->next;
	}
	a->value = temp;
	if (rr == 0)
		ft_putstr_fd("ra\n", 1);
	return ;
}

void	rb(t_stack *b, int rr)
{
	int temp;

	if (b == NULL || b->next == NULL)
		return;
	temp = b->value;
	while (b->next != NULL)
	{
		b->value = b->next->value;
		b = b->next;
	}
	b->value = temp;
	if (rr == 0)
		ft_putstr_fd("rb\n", 1);
	return ;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 1);
	rb(b, 1);
	ft_putstr_fd("rr\n", 1);
	return ;
}