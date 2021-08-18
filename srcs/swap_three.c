#include <push_swap.h>

void	swap_three(t_stack *a)
{
	if (a->value > a->next->value && a->next->value < a->next->next->value && a->next->next->value > a->value)
	{
		sa(a);
		stackclear(&a);
		exit(0);
	}
	else if (a->value > a->next->value && a->next->value > a->next->next->value && a->next->next->value < a->value)
	{
		sa(a);
		rra(a, 0);
		stackclear(&a);
		exit(0);
	}
	else if (a->value > a->next->value && a->next->value < a->next->next->value && a->next->next->value < a->value)
	{
		ra(a, 0);
		stackclear(&a);
		exit(0);
	}
	else if (a->value < a->next->value && a->next->value > a->next->next->value && a->next->next->value > a->value)
	{
		sa(a);
		ra(a, 0);
		stackclear(&a);
		exit(0);
	}
	else if (a->value < a->next->value && a->next->value > a->next->next->value && a->next->next->value < a->value)
	{
		rra(a, 0);
		stackclear(&a);
		exit (0);
	}
}