#include <push_swap.h>
#include <libft.h>
#include <stdlib.h>

int	main(int av, char **argc)
{
	ft_putnbr_fd(av, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(argc[0], 1);
	ft_putchar_fd('\n', 1);

	t_stack	*a;
	a = malloc(sizeof(t_stack));
	a->value = malloc(sizeof(int));
	a->value = (void*)42;

	t_stack	*b;
	b = malloc(sizeof(t_stack));
	b->value = malloc(sizeof(int));
	b->value = (void*)43;

	a->next = b;

	ft_putnbr_fd((int)a->value, 1);
	ft_putnbr_fd((int)a->next->value, 1);

	free(b);
	free(a);
	return (0);
}