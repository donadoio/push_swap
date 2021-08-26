/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils_a.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 17:04:51 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 19:14:30 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*stack_last(t_stack *node, t_data *data, char *stack)
{
	int	i;

	i = 0;
	if (ft_strncmp(stack, "a", 1) == 0)
	{
		while (i < data->a_count - 1)
		{
			node = node->next;
			i++;
		}
	}
	else if (ft_strncmp(stack, "b", 1) == 0)
	{
		while (i < data->b_count - 1)
		{
			node = node->next;
			i++;
		}
	}
	return (node);
}

int	num_check(char **argv, int args)
{
	int	i;
	int	j;

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
	t_dup_check	vars;

	vars.i = 1;
	vars.j = vars.i + 1;
	while (vars.i <= args)
	{
		vars.j = vars.i + 1;
		while (vars.j <= args)
		{
			vars.len1 = ft_strlen(argv[vars.i]);
			vars.len2 = ft_strlen(argv[vars.j]);
			if (vars.len1 > vars.len2)
				vars.len3 = vars.len1;
			else
				vars.len3 = vars.len2;
			if (ft_strncmp(argv[vars.i], argv[vars.j], vars.len3) == 0)
			{
				ft_putstr_fd("Error\nSome arguements are duplicated.\n", 1);
				return (-1);
			}
			vars.j++;
		}
		vars.i++;
	}
	return (0);
}

int	int_check(char **argv, int args)
{
	long	a;
	int		i;

	i = 1;
	while (i <= args)
	{
		a = ft_atoi_long(argv[i]);
		if (a > 2147483647 || a < -2147483648)
		{
			ft_putstr_fd("Error\nSome arguements \
are bigger than an interger.\n", 1);
			return (-1);
		}
		i++;
	}
	return (0);
}
