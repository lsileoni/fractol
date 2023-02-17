CC=cc
CFLAGS= -Wall -Wextra -Werror -march=skylake -Ofast -g
INCLUDES=-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -I /usr/local/include -L./libft/build/ -lft
CFILES=fractol.c switchboard.c color_handler.c colorschemes.c set_checks.c initializations.c complex_utilities.c hooks.c zoom_handlers.c paint.c event_checks.c
OFILES=$(CFILES:.c=.o)

NAME=fractol

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(OFILES) -o $(NAME) $(CFLAGS) $(INCLUDES)

$(OFILES): $(CFILES)
	$(CC) -c $(CFILES) $(CFLAGS)
