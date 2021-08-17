#include <push_swap.h>

void	ra(t_stack *a)
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
	return ;
}

void	rb(t_stack *b)
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
	return ;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	return ;
}