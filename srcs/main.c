#include <push_swap.h>

void	print_list(t_stack *node)
{
	if (node != NULL)
	{
		while (node->next != NULL)
		{
			ft_putstr_fd("Value: ", 1);
			ft_putnbr_fd(node->value, 1);
			ft_putchar_fd('\n', 1);
			node = node->next;
		}
		if (node != NULL)
		{
			ft_putstr_fd("Value: ", 1);
			ft_putnbr_fd(node->value, 1);
			ft_putchar_fd('\n', 1);
		}
	}
	return ;
}

int	num_check(char **argv, int args)
{
	int i;
	int j;

	i = 1;
	while (i <= args)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (j == 0 && argv[i][j] == '-')
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
			{
				ft_putstr_fd("Error\nSome arguements aren't intergers.\n", 1);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	dup_check(char **argv, int args)
{
	int i;
	int j;
	size_t len1;
	size_t len2;
	size_t len3;

	i = 1;
	j = i + 1;
	while (i <= args)
	{
		j = i + 1;
		while (j <= args)
		{
			len1 = ft_strlen(argv[i]);
			len2 = ft_strlen(argv[j]);
			if (len1 > len2)
				len3 = len1;
			else
				len3 = len2;
			if (ft_strncmp(argv[i], argv[j], len3) == 0)
			{
				ft_putstr_fd("Error\nSome arguements are duplicated.\n", 1);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	int_check(char **argv, int args)
{
	long a;
	int i;

	i = 1;
	while (i <= args)
	{
		a = ft_atoi_long(argv[i]);
		if (a > 2147483647 || a < -2147483648)
		{
			ft_putstr_fd("Error\nSome arguements are bigger than an interger.\n", 1);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	args;
	int i;
	t_data	*data;

	args = argc - 1;
	i = 1;
	if (argc < 3)
		return (0);
	if (num_check(argv, args) == -1 || dup_check(argv, args) == -1 \
	|| int_check(argv, args) == -1)
		return (0);
	data = malloc(sizeof(t_data));
	data->a = stack_new(ft_atoi(argv[i]));
	data->a_count = 1;
	i++;
	while (i <= args)
	{
		add_to_stack(data, ft_atoi(argv[i]), "a");
		i++;
	}
	data->b = NULL;
	data->b_count = 0;
	if (is_sorted(data->a) == 1)
	{
		stackclear(&data->a);
		return (0);
	}
	else if (data->a_count == 2)
	{
		sa(data->a);
		stackclear(&data->a);
		return (0);
	}
	else if (data->a_count == 3)
		swap_three(data);
	else if (data->a_count == 4)
		swap_four(data);
	else if (data->a_count == 5)
		swap_five(data);
	else if (data->a_count == 6)
		swap_six(data);
	
	printf("Stack A sorted?: %d\n", is_sorted(data->a));
	pb(&data->a, &data->b, data);
	printf("Stack A Count: %d\nStack B Count: %d\n", data->a_count, data->b_count);
	ft_putstr_fd("Stack a:\n", 1);
	print_list(data->a);
	ft_putstr_fd("Stack b:\n", 1);
	print_list(data->b);
	stackclear(&data->a);
	stackclear(&data->b);
	return (0);
}