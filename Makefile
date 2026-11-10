NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = cc
SRC =  ft_printf.c helper_functions.c print_format.c
OBGS = $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(OBGS)
	ar rcs $(NAME) $(OBGS) 

%.o: %.c  libftprintf
	$(CC) $(FLAGS) -c $< -o $@


clean :
	rm -f $(OBGS)
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONEY : clean