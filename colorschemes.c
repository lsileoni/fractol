/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorschemes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:25:32 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/22 20:18:25 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	colorschemes(unsigned char color, unsigned int pixel, \
					unsigned char iterations, char *buffer)
{
	if (color == RED_GLOW)
	{
		buffer[pixel] = (unsigned char)(0);
		buffer[pixel + 1] = (unsigned char)(0);
		buffer[pixel + 2] = (unsigned char)(iterations * 255 * 10);
		buffer[pixel + 3] = (unsigned char)0;
	}
	if (color == GREEN_GLOW)
	{
		buffer[pixel] = (unsigned char)(0);
		buffer[pixel + 1] = (unsigned char)(iterations * 255 * 10);
		buffer[pixel + 2] = (unsigned char)(0);
		buffer[pixel + 3] = (unsigned char)0;
	}
	if (color == BLUE_GLOW)
	{
		buffer[pixel] = (unsigned char)(iterations * 255 * 10);
		buffer[pixel + 1] = (unsigned char)(0);
		buffer[pixel + 2] = (unsigned char)(0);
		buffer[pixel + 3] = (unsigned char)0;
	}
}
