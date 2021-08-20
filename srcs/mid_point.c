#include <push_swap.h>
static	void	set_data(t_data **sorter_data)
{
	*sorter_data = malloc(sizeof(t_data));
	(*sorter_data)->a = NULL;
	(*sorter_data)->b = NULL;
	(*sorter_data)->a_count = 0;
	(*sorter_data)->b_count = 0;
	return ;
}
static	int		count_and_copy(t_data **sorter_data, t_stack *node)
{
	int 	mid_index;
	int 	size;
	t_stack *temp;

	size = 0;
	set_data(sorter_data);
	temp = node->previous;
	(*sorter_data)->a = stack_new(node->value);
	(*sorter_data)->a_count++;
	node = node->next;
	size++;
	while (node != temp)
	{
		add_to_stack(*sorter_data, node->value, "a");
		node = node->next;
		size++;
	}
	add_to_stack(*sorter_data, node->value, "a");
	size++;
	mid_index = size / 2;
	return (mid_index);
}

static	void sort_the_stack(t_data *sorter_data)
{
	while (sorter_data->a_count != 0)
	{
		if (is_smallest(sorter_data->a, sorter_data->a->value, sorter_data, "a") == 1)
			pb_silent(&sorter_data->a, &sorter_data->b, sorter_data);
		else
			ra_silent(sorter_data->a, sorter_data);
	}
	while (sorter_data->b_count != 0)
		pa_silent(&sorter_data->a, &sorter_data->b, sorter_data);
}

int	mid_point(t_stack *node)
{
	int 	mid_index;
	int		i;
	int		mid_point;
	t_data 	*sorter_data;
	t_stack	*temp;

	sorter_data = NULL;
	mid_index = count_and_copy(&sorter_data, node);
	sort_the_stack(sorter_data);
	i = 0;
	temp = sorter_data->a;
	while (i != mid_index)
	{
		temp = temp->next;
		i++;
	}
	mid_point = temp->value;
	stackclear(&sorter_data->a, sorter_data, "a");
	free(sorter_data);
	return (mid_point);
}