#include <push_swap.h>

//Function to be used exclusively for testing purposes.

static void	print_a(t_stack *node, t_data *data)
{
	int i;

	i = 0;
	ft_putstr_fd("Stack A: \n", 1);
	while (i < data->a_count)
	{
		ft_putstr_fd("Value: ", 1);
		ft_putnbr_fd(node->value, 1);
		ft_putchar_fd('\n', 1);
		node = node->next;
		i++;
	}
	return ;
}

static void	print_b(t_stack *node, t_data *data)
{
	int i;

	i = 0;
	ft_putstr_fd("Stack B: \n", 1);
	while (i < data->b_count)
	{
		ft_putstr_fd("Value: ", 1);
		ft_putnbr_fd(node->value, 1);
		ft_putchar_fd('\n', 1);
		node = node->next;
		i++;
	}
	return ;
}

void	print_list(t_stack *node, t_data *data, char *stack)
{
	if (node != NULL)
	{
		if (ft_strncmp("a", stack, 1) == 0)
			print_a(node, data);
		else if (ft_strncmp("b", stack, 1) == 0)
			print_b(node, data);
	}
	return ;
}