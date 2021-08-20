#include <push_swap.h>

static int	lesser_amount(t_data *data, int mid)
{
	int i;
	int	amount;
	t_stack	*temp;

	i = 0;
	amount = 0;
	temp = data->a;
	while (i < data->a_count)
	{
		if (mid > temp->value)
			amount++;
		temp = temp->next;
		i++;
	}
	return (amount);
}

static	void	add_chunk(t_chunks	**chunks, int amount)
{
	t_chunks	*last;
	t_chunks	*temp;

	last = NULL;

	if (*chunks == NULL)
	{
		(*chunks) = malloc(sizeof(t_chunks));
		(*chunks)->amount = amount;
		(*chunks)->next = NULL;
	}
	else
	{
		temp = *chunks;
		while (temp->next != NULL)
			temp = temp->next;
		last = malloc(sizeof(t_chunks));
		temp->next = last;
		last->amount = amount;
		last->next = NULL;
	}
	return ;
}

void	swap_large(t_data *data)
{
	int size;
	int	mid;
	int	lesser;

	data->chunks = NULL;
	size = data->a_count;
	while (data->a_count > 2 || is_sorted(data->a, data, "a") != 1)
	{
		mid = mid_point(data->a);
		lesser = lesser_amount(data, mid);
		add_chunk(&(data->chunks), lesser);
		while (data->a->value < mid)
		{
			lesser--;
			pb(&data->a, &data->b, data);
		}
		if (data->a->previous->value < mid)
			while (data->a->previous->value < mid)
			{
				lesser--;
				rra(data->a, 0, data);
				pb(&data->a, &data->b, data);
			}
		while (lesser != 0)
		{
			ra(data->a, 0, data);
			if (data->a->value < mid)
				pb(&data->a, &data->b, data);
		}
	}
	if (data->a_count == 2 && data->a->value > data->a->next->value)
		sa(data->a);


	// Part after everything is passed to stack B
	// Chunks are created, you must make function to delete all chunks after
	// Figure out how to use the chunk linked list to move from B to A
	print_list(data->a, data, "a");
	print_list(data->b, data, "b");
	return ;
}