#include <push_swap.h>
#include <libft.h>

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
	stackclear(b);

	return (0);
}