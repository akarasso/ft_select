CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

NAME	= test

HEADERS	= ./includes ./libft/includes

SOURCES	= ./srcs/ft_catch_signal.c	./srcs/ft_check_termcaps.c	./srcs/ft_clear_exit.c			\
	./srcs/ft_err.c			./srcs/ft_fullscreen.c		./srcs/ft_init_sreen.c			\
	./srcs/ft_init_term.c		./srcs/ft_putint.c		./srcs/ft_resize_win.c			\
	./srcs/main.c			

OBJ	= $(SOURCES:.c=.o)

HEADER_LIST	= $(addprefix -I,$(HEADERS))

all	: $(NAME)

makelib	: 
	make -C libft/

cleanlib	: 
	make clean -C libft/

fcleanlib	: 
	make fclean -C libft/

%.o	: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(HEADER_LIST) -c -o $@ $<

$(NAME)	: $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(HEADER_LIST) -o $(NAME) $(OBJ) ./libft/libft.a

clean	: cleanlib
	rm -f $(OBJ)

re	: fcleanlib fclean all

fclean	: cleanlib clean
	rm -f $(NAME)

