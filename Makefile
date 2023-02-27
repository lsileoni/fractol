CC=cc
CFLAGS= -Wall -Wextra -Werror -g -march=skylake -Ofast
INCLUDES=-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -I /usr/local/include -L./libft/build/ -lft -lm

CFILES=fractol.c \
	   switchboard.c \
	   colorschemes.c \
	   set_checks.c \
	   initializations.c \
	   hooks.c \
	   zoom_handlers.c \
	   paint.c \
	   event_checks.c \
	   ft_atod.c \
	   arg_parser.c \
	   double_parsing.c

BFILES=fractol_bonus.c \
	   switchboard_bonus.c \
	   colorboard_bonus.c \
	   colorschemes_bonus.c \
	   set_checks_bonus.c \
	   initializations_bonus.c \
	   complex_utilities_bonus.c \
	   hooks_bonus.c \
	   zoom_handlers_bonus.c \
	   paint_bonus.c \
	   event_checks_bonus.c \
	   ft_atod_bonus.c \
	   arg_parser_bonus.c \
	   double_parsing_bonus.c

OFILES=$(CFILES:.c=.o)
BOFILES=$(BFILES:.c=.o)

NAME=./build/mandatory/fractol
BNAME=./build/bonus/fractol

all: $(NAME)

bonus: $(BNAME)

$(NAME): $(OFILES)
	mkdir -p build
	mkdir -p build/mandatory
	$(CC) $(OFILES) -o $(NAME) $(CFLAGS) $(INCLUDES)

$(OFILES): $(CFILES)
	$(CC) -c $(CFILES) $(CFLAGS)

$(BNAME): $(BOFILES)
	$(CC) $(BOFILES) -o $(BNAME) $(CFLAGS) $(INCLUDES)

$(BOFILES): $(BFILES)
	mkdir -p build
	mkdir -p build/bonus
	$(CC) -c $(BFILES) $(CFLAGS)

clean:
	rm -f $(OFILES) $(BOFILES)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

bonus_re: fclean bonus

.PHONY: all clean fclean re bonus bonus_re
