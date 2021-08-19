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

void		swap_four(t_data *data)
{
	pb(&data->a, &data->b);
	sub_swap(data->a);
	while (data->b != NULL)
	{
		if (is_smallest(data->a, data->b->value) == 1)
			pa(&data->a, &data->b);
		else if (is_biggest(data->a, data->b->value))
		{
			pa(&data->a, &data->b);
			ra(data->a, 0);
		}
		else if (data->b->value > data->a->value && data->b->value < data->a->next->value)
		{
			ra(data->a, 0);
			pa(&data->a, &data->b);
			rra(data->a, 0);
		}
		else if (data->b->value > data->a->next->value && data->b->value < data->a->next->next->value)
		{
			ra(data->a, 0);
			ra(data->a, 0);
			pa(&data->a, &data->b);
			rra(data->a, 0);
			rra(data->a, 0);
		}
		else if (data->b->value > data->a->next->next->value && data->b->value < data->a->next->next->next->value)
		{
			rra(data->a, 0);
			pa(&data->a, &data->b);
			ra(data->a, 0);
			ra(data->a, 0);
		}
	}
	stackclear(&data->a);
	exit (0);
	return ;
}