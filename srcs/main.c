#include <push_swap.h>
#include <libft.h>

t_stack	*stack_new(int	number)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->value = number;
	new->next = NULL;
	return (new);
}

t_stack	*stack_last(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_add_front(t_stack **list, t_stack *new)
{
	new->next = *list;
	return ;
}

void	stack_add_back(t_stack	**list, t_stack *new)
{
	t_stack *last;

	last = stack_last(*list);
	last->next = new;
	last->next->next = NULL;
	return ;
}

int		stack_size(t_stack	*stack)
{
	int i;

	i = 0;
	if (stack != NULL)
		i++;
	while (stack->next != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	main(int av, char **argc)
{
	ft_putnbr_fd(av, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(argc[0], 1);
	ft_putchar_fd('\n', 1);

	t_stack	*a;
	t_stack	*b;

	a = stack_new(42);
	b = stack_new(43);

	stack_add_front(&a, b);
	ft_putstr_fd("Value of second: ", 1);
	ft_putnbr_fd(b->next->value, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Stack size: ", 1);
	ft_putnbr_fd(stack_size(b), 1);
	ft_putchar_fd('\n', 1);

	t_stack *c;
	c = stack_new(55);
	stack_add_back(&b, c);
	ft_putstr_fd("Stack size: ", 1);
	ft_putnbr_fd(stack_size(b), 1);
	ft_putchar_fd('\n', 1);

	t_stack *last = stack_last(b);
	ft_putstr_fd("Value of last: ", 1);
	ft_putnbr_fd(last->value, 1);
	ft_putchar_fd('\n', 1);

	free(b);
	free(a);
	free(c);
	return (0);
}