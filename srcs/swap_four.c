#include <push_swap.h>

static void	sub_swap(t_stack *a)
{
	if (a->value > a->next->value && a->next->value < a->next->next->value && a->next->next->value > a->value)
		sa(a);
	else if (a->value > a->next->value && a->next->value > a->next->next->value && a->next->next->value < a->value)
	{
		sa(a);
		rra(a, 0);
	}
	else if (a->value > a->next->value && a->next->value < a->next->next->value && a->next->next->value < a->value)
		ra(a, 0);
	else if (a->value < a->next->value && a->next->value > a->next->next->value && a->next->next->value > a->value)
	{
		sa(a);
		ra(a, 0);
	}
	else if (a->value < a->next->value && a->next->value > a->next->next->value && a->next->next->value < a->value)
		rra(a, 0);
}

void		swap_four(t_stack *a, t_stack *b)
{
	pb(&a, &b);
	sub_swap(a);
	while (b != NULL)
	{
		if (is_smallest(a, b->value) == 1)
			pa(&a, &b);
		else if (is_biggest(a, b->value))
		{
			pa(&a, &b);
			ra(a, 0);
		}
		else if (b->value > a->value && b->value < a->next->value)
		{
			ra(a, 0);
			pa(&a, &b);
			rra(a, 0);
		}
		else if (b->value > a->next->value && b->value < a->next->next->value)
		{
			ra(a, 0);
			ra(a, 0);
			pa(&a, &b);
			rra(a, 0);
			rra(a, 0);
		}
		else if (b->value > a->next->next->value && b->value < a->next->next->next->value)
		{
			rra(a, 0);
			pa(&a, &b);
			ra(a, 0);
			ra(a, 0);
		}
	}
	stackclear(&a);
	exit (0);
	return ;
}