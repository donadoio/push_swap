#include <push_swap.h>

void	print_list(t_stack *node)
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
				ft_putstr_fd("Error\nSome arguements are bigger than an interger.\n", 1);
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
	t_stack	*a;

	args = argc - 1;
	i = 1;
	if (argc < 3)
		return (0);
	if (num_check(argv, args) == -1 || dup_check(argv, args) == -1 \
	|| int_check(argv, args) == -1)
		return (0);
	a = stack_new(ft_atoi(argv[i]));
	i++;
	while (i <= args)
	{
		add_to_stack(a, ft_atoi(argv[i]));
		i++;
	}
	print_list(a);
	stackclear(a);
	return (0);
}