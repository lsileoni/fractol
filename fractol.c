#include "fractol.h"
#include "./libft/src/libft.h"
#include "minilibx_opengl/mlx.h"

void	check_modifier_actions(t_app *app)
{
	t_flags		*flags;
	t_window	*win;

	flags = app->flags;
	win = app->params->window_params;
	if (flags->i_key)
	{
		app->params->iter_max += 1;
		paint_pattern(app);
		return ;
	}
	if (flags->z_key)
	{
		zoom_in_static(app->params);
		paint_pattern(app);
		return ;
	}
	if (flags->c_key)
	{
		app->params->color_scheme++;
		paint_pattern(app);
		return ;
	}
	if (flags->r_key)
	{
		win->max_width = 2.5;
		win->min_width = -2.5;
		win->max_height = 2.5;
		win->min_height = -2.5;
		app->params->movement_factor = 1.0;
		win->pixel_width = (win->max_width - win->min_width) / win->window_width;
		win->pixel_height = (win->max_height - win->min_height) / win->window_height;
		paint_pattern(app);
		return ;
	}
	if (flags->h_key)
	{
		app->draw_text *= -1;
		paint_pattern(app);
		return ;
	}
}

void	check_movement_actions(t_app *app)
{
	t_flags		*flags;
	t_window	*win;

	flags = app->flags;
	win = app->params->window_params;
	if (flags->left_arrow)
	{
		win->min_width -= 0.1 / app->params->movement_factor;
		win->max_width -= 0.1 / app->params->movement_factor;
		paint_pattern(app);
		return ;
	}
	if (flags->right_arrow)
	{
		win->min_width += 0.1 / app->params->movement_factor;
		win->max_width += 0.1 / app->params->movement_factor;
		paint_pattern(app);
		return ;
	}
	if (flags->up_arrow)
	{
		win->max_height -= 0.1 / app->params->movement_factor;
		win->min_height -= 0.1 / app->params->movement_factor;
		paint_pattern(app);
		return ;
	}
	if (flags->down_arrow)
	{
		win->max_height += 0.1 / app->params->movement_factor;
		win->min_height += 0.1 / app->params->movement_factor;
		paint_pattern(app);
		return ;
	}
}

void	check_mouse_actions(t_app *app)
{
	t_flags		*flags;

	flags = app->flags;
	if (app->flags->scroll_up)
	{
		zoom_in_complex(app, app->params->mouse_x, app->params->mouse_y);
	}
	if (app->flags->scroll_down)
	{
		zoom_out_static(app);
	}
}

int	render_frame(t_app *app)
{
	if (app->flags->esc)
	{
		mlx_destroy_image(app->mlx, app->img);
		mlx_destroy_window(app->mlx, app->win);
		free(app->params->window_params);
		free(app->params->set);
		free(app->params);
		free(app->fb);
		free(app->flags);
		free(app);
		exit(0);
		return (0);
	}
	check_mouse_actions(app);
	check_modifier_actions(app);
	check_movement_actions(app);
	ft_bzero(app->flags, sizeof(t_flags));
	return (0);
}

void	define_hooks(t_app *app)
{
	mlx_hook(app->win, 2, 1L<<0, key_down, app);
	mlx_hook(app->win, 4, 1L<<0, mouse_hook, app);
	mlx_hook(app->win, 17, 1L<<0, close_window, app);
	mlx_loop_hook(app->mlx, render_frame, app);
}

int	main(int argc, char **argv)
{
	t_app			*app;
	t_params		*params;
	t_set			*set;
	t_framebuffer	*fb;

	if (!(params = init_params(ft_atoi(argv[2]), ft_atoi(argv[3]))) || argc < 2)
		exit(1);
	if (!(app = init_app(params)))
	{
		free(params);
		exit(1);
	}
	app->params = params;
	if (!(set = init_set(argv[1])) || !(fb = init_framebuffer(app)))
	{
		free(params);
		free(app);
		exit(1);
	}
	params->set = set;
	app->fb = fb;
	define_hooks(app);
	paint_pattern(app);
	mlx_loop(app->mlx);
	return (0);
}
