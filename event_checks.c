/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:25:54 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/27 12:05:25 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_mouse_actions(t_app *app)
{
	t_flags	*flags;

	flags = app->flags;
	if (app->flags->scroll_up)
		zoom_in_complex(app, app->params->mouse_x, app->params->mouse_y);
	if (app->flags->scroll_down)
		zoom_out_static(app);
}
