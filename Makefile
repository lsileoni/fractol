all:
	cc -g -I /usr/local/include fractol.c switchboard.c handlers.c color_handler.c colorschemes.c set_checks.c initializations.c complex_utilities.c hooks.c zoom_handlers.c paint.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror -L./libft/build/ -lft -o fractol -march=skylake -Ofast
