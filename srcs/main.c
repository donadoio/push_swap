/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 17:10:15 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 19:39:48 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	negative_proof(t_data *data)
{
	int		i;
	t_stack	*temp;
	int		negative;
	long	least;

	i = 0;
	negative = 0;
	least = 0;
	temp = data->a;
	while (i < data->a_count && negative == 0)
	{
		if (temp->value < 0)
			negative = 1;
		i++;
		temp = temp->next;
	}
	if (negative == 1)
	{
		least = find_minimum(data);
		least = least * -1;
		add_least(data, least);
	}
	return ;
}

static void	which_swap(t_data *data)
{
	if (is_sorted(data->a, data, "a") == 1)
	{
		stackclear(&data->a, data, "a");
		exit(0);
	}
	else if (data->a_count == 2)
	{
		sa(data->a);
		stackclear(&data->a, data, "a");
		exit(0);
	}
	else if (data->a_count == 3)
		swap_three(data);
	else if (data->a_count == 4)
		swap_four(data);
	else if (data->a_count == 5)
		swap_five(data);
	else if (data->a_count > 5 && data->a_count <= 100)
		swap_hundred(data);
	else if (data->a_count > 100)
		swap_five_hundred(data);
	return ;
}

static void	run_push_swap(t_data *data)
{
	negative_proof(data);
	which_swap(data);
	stackclear(&data->a, data, "a");
	stackclear(&data->b, data, "b");
	free(data);
	return ;
}

static t_data	*malloc_protect(t_data *data)
{
	if (data == NULL)
		exit (-1);
	else
		return (data);
}

int	main(int argc, char **argv)
{
	int		args;
	int		i;
	t_data	*data;

	args = argc - 1;
	i = 1;
	if (argc < 3)
		return (0);
	if (num_check(argv, args) == -1 || dup_check(argv, args) == -1 \
	|| int_check(argv, args) == -1)
		return (0);
	data = malloc_protect(malloc(sizeof(t_data)));
	data->a = stack_new(ft_atoi(argv[i]));
	data->a_count = 1;
	data->b = NULL;
	data->b_count = 0;
	i++;
	while (i <= args)
	{
		add_to_stack(data, ft_atoi(argv[i]), "a");
		i++;
	}
	run_push_swap(data);
	return (0);
}
