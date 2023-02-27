/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switchboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:26:33 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/27 12:06:05 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	valid_key(int key)
{
	static int	key_values[] = {ESC, C_KEY};
	int			i;

	i = 0;
	while (i < KEY_COUNT)
	{
		if (key == key_values[i])
			return (1);
		i++;
	}
	return (0);
}

void	switchboard(int key, t_app *app)
{
	if (valid_key(key))
		app->flags->key_down_flags[key] = 1;
}
