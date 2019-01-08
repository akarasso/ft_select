CC	= gcc

CFLAGS	= -Wall -Werror -Wextra -g3

NAME	= test

HEADERS	= ./includes ./libft/includes

SOURCES	= ./srcs/ft_catch_signal.c \
	./srcs/ft_check_termcaps.c \
	./srcs/ft_clear_exit.c \
	./srcs/ft_err.c \
	./srcs/ft_enter_in_selection.c \
	./srcs/ft_init_sreen.c \
	./srcs/ft_init_term.c \
	./srcs/ft_free_opt.c \
	./srcs/ft_resize_win.c \
	./srcs/ft_putint.c \
	./srcs/ft_read_key.c \
	./srcs/ft_print_key.c \
	./srcs/key_handler/ft_down_arrow.c \
	./srcs/key_handler/ft_up_arrow.c \
	./srcs/key_handler/ft_left_arrow.c \
	./srcs/key_handler/ft_right_arrow.c \
	./srcs/key_handler/ft_open_select.c \
	./srcs/key_handler/ft_enter.c \
	./srcs/key_handler/ft_space.c \
	./srcs/key_handler/ft_research.c \
	./srcs/key_handler/ft_backspace.c \
	./srcs/key_handler/ft_escape.c \
	./srcs/display/ft_display.c \
	./srcs/display/ft_select_next.c \
	./srcs/display/ft_select_prev.c \
	./srcs/display/ft_toolbar.c \
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
	$(CC) $(CFLAGS) $(HEADER_LIST) -o $(NAME) $(OBJ) ./libft/libft.a -ltermcap

clean	: cleanlib
	rm -f $(OBJ)

re	: fcleanlib fclean all

fclean	: cleanlib clean
	rm -f $(NAME)
