NAME = push_swap

SRC = 	main.c\
		stack_utils_a.c\
		stack_utils_b.c\
		stack_utils_c.c\
		swaps_a.c\
		swaps_b.c\
		swaps_c.c\
		swap_three.c\
		swap_four.c\
		swap_five.c\
		swap_six.c

SRC_MAP = srcs/

SRCS = $(addprefix $(SRC_MAP), $(SRC))

HDRS = -I includes/ -I libft/hdrs

OBJS=$(SRCS:.c=.o)

LIBS = libft/libft.a

all: libft $(NAME)

$(NAME): $(OBJS)
	clang -o $@ $^  $(LIBS) $(HDRS) -Wall -Werror -Wextra -g -fsanitize=address

%.o: %.c
	clang -o $@ -c $< $(HDRS)  -Wall -Werror -Wextra -g -fsanitize=address

libft:
	$(MAKE) -C libft/ all

clean:
	$(RM) -f $(OBJS)
	$(MAKE) -C libft/ fclean

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: libft push_swap all clean fclean re
