#include "minilibx_opengl/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define KEY_COUNT 10
#define COLOR_SCHEMES 7
#define KEY_RANGE 127

enum e_keys 
{
	ESC=53,
	LEFT_ARROW=123,
	UP_ARROW=126,
	DOWN_ARROW=125,
	RIGHT_ARROW=124,
	I_KEY=34,
	Z_KEY=6,
	C_KEY=8,
	H_KEY=4,
	R_KEY=15
};

enum e_buttons {
	MOUSE_ONE_DOWN = 1,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5
};

enum e_sets 
{
	MANDELBROT,
	JULIA,
	THORN	
};

enum e_colors 
{
	NEON_ENERGY,
	WHITE_ENERGY,
	PINK_ENERGY,
	BLACK_WHITE,
	RED_GLOW,
	GREEN_GLOW,
	BLUE_GLOW
};

typedef struct s_complex
{
    double	r;
    double	i;
}	t_complex;

typedef struct s_framebuffer
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		pixel;
	char	*buffer;
}			t_framebuffer;

typedef struct s_set 
{
	t_complex		z;
	t_complex		z_s;
	t_complex		c;
	unsigned char	set_type;
}					t_set;

typedef struct s_window
{
	double			max_width;
	double			min_width;
	double			max_height;
	double			min_height;
	double			pixel_width;
	double			pixel_height;
	double			x_midpoint;
	double			y_midpoint;
	int				x;
	int				y;
	unsigned short	window_height;
	unsigned short	window_width;
}					t_window;

typedef struct	s_params
{
	t_set			*set;
	t_window		*window_params;
	double			movement_factor;
	double			mouse_x;
	double			mouse_y;
	unsigned int	iter_max;
	unsigned char	color_scheme;
}					t_params;

typedef struct s_flags
{
	unsigned char	esc;
	unsigned char	*key_down_flags;
	unsigned char	scroll_down;
	unsigned char	scroll_up;
	unsigned char	mouse_one_down;
	unsigned char	mouse_moved;
}					t_flags;

typedef struct	s_app
{
	t_params		*params;
	t_flags			*flags;
	t_framebuffer	*fb;
	void			*mlx;
	void			*win;
	void			*img;
	int				drawing;
	int				draw_text;
}					t_app;

void	paint_pattern(t_app *app);
void	switchboard(int key, t_app *app, unsigned char up_down);
void	handle_mouse_zoom(int key, t_complex z, t_app *vars);
void	handle_iterations(int key, t_app *vars);
void	energy(unsigned char color, unsigned int pixel, unsigned char iterations, char *buffer);
void	colorboard(unsigned char color, unsigned int pixel, unsigned char iterations, char *buffer);
void	glow(unsigned char color, unsigned int pixel, unsigned char iters, char *buf);
int	mandelbrot_check(int x, int y, t_params *p);
int julia_check(int x, int y, t_app *app);
int	thorn_check(int x, int y, t_params *p);
t_set			*init_set(char *set_name);
t_framebuffer	*init_framebuffer(t_app *vars);
t_app			*init_app(t_params *p);
t_params		*init_params(int h, int w);
void	zoom_out_static(t_app *vars);
int	close_window(t_app *vars);
int	key_down(int key, t_app *vars);
int	key_up(int key, t_app *vars);
int mouse_pos(int x, int y, t_app *vars);
int		mouse_hook(int button, int x, int y, t_app *app);
int	mouse_movement_hook(int x, int y, t_app *app);
void	zoom_out_static(t_app *app);
void	zoom_in_static(t_params *p);
void	zoom_in_complex(t_app *app, int x, int y);
t_complex	com_mul(t_complex a, t_complex b);
t_complex	com_add(t_complex a, t_complex b);
t_complex	com_div(t_complex x,t_complex y);
void	check_modifier_actions(t_app *app, t_window *win, unsigned char *key_down_flags);
void	check_movement_actions(t_app *app, t_window	*win, unsigned char *key_down_flags);
void	check_mouse_actions(t_app *app);
