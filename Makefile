NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = cc
SRC =  ft_printf.c helper_functions.c print_format.c print_null.c
OBGS = $(SRC:%.c=%.o)


all : $(NAME)

$(NAME) : $(OBGS)
	ar rcs $(NAME) $(OBGS) 

%.o: %.c ft_printf.h 
	$(CC) $(FLAGS) -c $< -o $@


clean :
	@rm -f $(OBGS)
fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : clean re all fclean
