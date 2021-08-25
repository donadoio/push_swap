static int first_is_biggest(t_data *data, int amount)
{
	int i;
	int first;
	t_stack	*temp;

	temp = data->b;
	first = temp->value;
	i = 0;
	while (i < amount)
	{
		if (temp->value > first)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

static int	greater_amount(t_data *data, int mid)
{
	int i;
	int	amount;
	t_stack	*temp;

	i = 0;
	amount = 0;
	temp = data->b;
	while (i < data->b_count)
	{
		if (mid < temp->value)
			amount++;
		temp = temp->next;
		i++;
	}
	return (amount);
}

static t_chunks	*get_last_chunk(t_data *data)
{
	t_chunks	*last;
	int i;

	i = 1;
	last = data->chunks;
	while (i != data->chunk_count)
	{
		last = last->next;
		i++;
	}
	return (last);
}