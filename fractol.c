/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:26:00 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/22 22:15:46 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	render_frame(t_app *app)
{
	unsigned char	*key_down;

	key_down = app->flags->key_down_flags;
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
	check_modifier_actions(app, key_down);
	ft_bzero(app->flags, sizeof(t_flags));
	app->flags->key_down_flags = key_down;
	return (0);
}

static void	define_hooks(t_app *app)
{
	mlx_hook(app->win, 2, 1L << 0, key_down, app);
	mlx_hook(app->win, 3, 1L << 0, key_up, app);
	mlx_hook(app->win, 4, 1L << 0, mouse_hook, app);
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

	if (!argument_parser(argc, argv, &args, &set))
		exit(1);
	if (!(init_params(args.x, args.y, &set, &params)))
		exit(1);
	if (!(init_app(&params, &args, &app)))
	{
		if (app.img)
			mlx_destroy_image(app.mlx, app.img);
		if (app.win)
			mlx_destroy_window(app.mlx, app.win);
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
