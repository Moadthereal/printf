NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = cc
SRC =  ft_printf.c helper_funcions.c print_u.c
OBGS = $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(OBGS)
	ar rcs $(NAME) $(OBGS) 

%.o: %.c 
	$(CC) $(FLAGS) -c $< -o $@


clean :
	rm -f $(OBGS)
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONEY : clean