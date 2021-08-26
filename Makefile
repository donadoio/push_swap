NAME = push_swap

SRC = 	main.c\
		stack_utils_a.c\
		stack_utils_b.c\
		stack_utils_c.c\
		swaps_a.c\
		swaps_b.c\
		swaps_c.c\
		swaps_d.c\
		swaps_e.c\
		swap_three.c\
		swap_four.c\
		swap_five.c\
		swap_hundred.c\
		swap_five_hundred.c\
		swap_large_a.c\
		swap_large_b.c\
		swap_large_c.c

SRC_MAP = srcs/

SRCS = $(addprefix $(SRC_MAP), $(SRC))

HDRS = -I includes/ -I libft/hdrs

OBJS=$(SRCS:.c=.o)

LIBS = libft/libft.a

all: libft $(NAME)

$(NAME): $(OBJS)
	@clang -o $@ $^  $(LIBS) $(HDRS) -Wall -Werror -Wextra -g -fsanitize=address
	@echo "\033[1m\033[32mSuccessfully Compiled\033[39m"

%.o: %.c
	@clang -o $@ -c $< $(HDRS)  -Wall -Werror -Wextra -g -fsanitize=address

libft:
	@$(MAKE) -C libft/ all

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C libft/ clean
	@echo "\033[1m\033[33mCleaning Object Files\033[39m"

fclean: clean
	@$(MAKE) -C libft/ fclean
	@$(RM) $(NAME)
	@echo "\033[1m\033[31mPurged Objects and Executables\033[39m"

re: fclean all

.PHONY: libft push_swap all clean fclean re
