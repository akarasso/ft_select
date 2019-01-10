CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

NAME	= test

HEADERS	= ./includes ./libft/includes

SOURCES	= ./srcs/ft_err.c				./srcs/ft_putint.c			\
	./srcs/ft_print_key.c			./srcs/main.c					\
	./srcs/display/ft_select_prev.c		./srcs/display/ft_select_next.c		./srcs/display/ft_display.c			\
	./srcs/display/ft_toolbar.c		./srcs/init/ft_check_termcaps.c		./srcs/init/ft_init_screen.c			\
	./srcs/init/ft_init_term.c		./srcs/init/ft_init_selection.c		./srcs/key_handler/ft_left_arrow.c		\
	./srcs/key_handler/ft_escape.c		./srcs/key_handler/ft_up_arrow.c	./srcs/key_handler/ft_right_arrow.c		\
	./srcs/key_handler/ft_down_arrow.c	./srcs/key_handler/ft_backspace.c	./srcs/key_handler/ft_open_select.c		\
	./srcs/key_handler/ft_research.c	./srcs/key_handler/ft_space.c		./srcs/key_handler/ft_read_key.c		\
	./srcs/key_handler/ft_enter.c		./srcs/signal/ft_resize_win.c		./srcs/signal/ft_catch_signal.c			\
	./srcs/options/ft_create_option.c	./srcs/options/ft_option_add.c ./srcs/options/ft_reset_mode.c \
	./srcs/ft_get_color.c ./srcs/display/ft_fill_line.c ./srcs/display/ft_toolbar_len.c ./srcs/ft_free_args.c \
	./srcs/ft_print_args.c ./srcs/display/ft_display_help.c ./srcs/key_handler/ft_help.c

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
	$(CC) $(CFLAGS) $(HEADER_LIST) -g3  -c -o $@ $<

$(NAME)	: $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(HEADER_LIST) -o $(NAME) $(OBJ) ./libft/libft.a -ltermcap

clean	: cleanlib
	rm -f $(OBJ)

re	: fcleanlib fclean all

fclean	: cleanlib clean
	rm -f $(NAME)
