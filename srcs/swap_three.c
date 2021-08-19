#include <push_swap.h>

void	swap_three(t_data *data)
{
	if (data->a->value > data->a->next->value && data->a->next->value < data->a->next->next->value && data->a->next->next->value > data->a->value)
	{
		sa(data->a);
		stackclear(&data->a, data, "a");
		exit(0);
	}
	else if (data->a->value > data->a->next->value && data->a->next->value > data->a->next->next->value && data->a->next->next->value < data->a->value)
	{
		sa(data->a);
		rra(data->a, 0, data);
		stackclear(&data->a, data, "a");
		exit(0);
	}
	else if (data->a->value > data->a->next->value && data->a->next->value < data->a->next->next->value && data->a->next->next->value < data->a->value)
	{
		ra(data->a, 0, data);
		stackclear(&data->a, data, "a");
		exit(0);
	}
	else if (data->a->value < data->a->next->value && data->a->next->value > data->a->next->next->value && data->a->next->next->value > data->a->value)
	{
		sa(data->a);
		ra(data->a, 0, data);
		stackclear(&data->a, data, "a");
		exit(0);
	}
	else if (data->a->value < data->a->next->value && data->a->next->value > data->a->next->next->value && data->a->next->next->value < data->a->value)
	{
		rra(data->a, 0, data);
		stackclear(&data->a, data, "a");
		exit (0);
	}
}