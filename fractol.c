/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:26:00 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/20 09:48:59 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/src/libft.h"
#include "fractol.h"
#include "minilibx_opengl/mlx.h"

int	render_frame(t_app *app)
{
	unsigned char	mouse_one_down;
	unsigned char	*key_down;

	key_down = app->flags->key_down_flags;
	mouse_one_down = app->flags->mouse_one_down;
	if (key_down[ESC])
	{
		mlx_destroy_image(app->mlx, app->img);
		mlx_destroy_window(app->mlx, app->win);
		free(app->params->window_params);
		free(app->flags->key_down_flags);
		free(app->flags);
		exit(0);
		return (0);
	}
	check_mouse_actions(app);
	check_modifier_actions(app, app->params->window_params, key_down);
	check_movement_actions(app, app->params->window_params, key_down);
	ft_bzero(app->flags, sizeof(t_flags));
	app->flags->key_down_flags = key_down;
	app->flags->mouse_one_down = mouse_one_down;
	return (0);
}

static void	define_hooks(t_app *app)
{
	mlx_hook(app->win, 2, 1L << 0, key_down, app);
	mlx_hook(app->win, 3, 1L << 0, key_up, app);
	mlx_hook(app->win, 4, 1L << 0, mouse_hook, app);
	mlx_hook(app->win, 6, 1L << 0, mouse_movement_hook, app);
	mlx_hook(app->win, 17, 1L << 0, close_window, app);
	mlx_loop_hook(app->mlx, render_frame, app);
}

static void	init_framebuffer(t_app *app, t_framebuffer *fb)
{
	ft_bzero(fb, sizeof(t_framebuffer));
	fb->buffer = mlx_get_data_addr(app->img, &fb->pixel_bits, &fb->line_bytes,
			&fb->endian);
}

int	main(int argc, char **argv)
{
	t_app			app;
	t_set			set;
	t_params		params;
	t_framebuffer	fb;
	t_args			args;

	if(!argument_parser(argc, argv, &args, &set))
		exit(1);
	if (!(init_params(args.x, args.y, &set, &params)))
		exit(1);
	if (!(init_app(&params, &args, &app)))
	{
		free(params.window_params);
		exit(1);
	}
	init_framebuffer(&app, &fb);
	app.fb = &fb;
	define_hooks(&app);
	paint_pattern(&app);
	mlx_loop(app.mlx);
	return (0);
}
