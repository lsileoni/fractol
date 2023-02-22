/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorschemes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <lsileoni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:25:32 by lsileoni          #+#    #+#             */
/*   Updated: 2023/02/19 22:25:33 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	energy(unsigned char color, unsigned int pixel, unsigned char iters,
		char *buf)
{
	if (color == WHITE_ENERGY)
	{
		buf[pixel] = (unsigned char)(255 * 10);
		buf[pixel + 1] = (unsigned char)(255 * 15);
		buf[pixel + 2] = (unsigned char)(iters * 255 * 40);
		buf[pixel + 3] = (unsigned char)0;
	}
	if (color == NEON_ENERGY)
	{
		buf[pixel] = (unsigned char)(255);
		buf[pixel + 1] = (unsigned char)(iters * 255 * 15);
		buf[pixel + 2] = (unsigned char)(iters * 255 * 40);
		buf[pixel + 3] = (unsigned char)0;
	}
	if (color == PINK_ENERGY)
	{
		buf[pixel] = (unsigned char)(255 * 10);
		buf[pixel + 1] = (unsigned char)(iters * 255 * 40);
		buf[pixel + 2] = (unsigned char)(255 * 15);
		buf[pixel + 3] = (unsigned char)0;
	}
}

void	glow(unsigned char color, unsigned int pixel, unsigned char iters,
		char *buf)
{
	if (color == RED_GLOW)
	{
		buf[pixel] = (unsigned char)(0);
		buf[pixel + 1] = (unsigned char)(0);
		buf[pixel + 2] = (unsigned char)(iters * 255 * 10);
		buf[pixel + 3] = (unsigned char)0;
	}
	if (color == GREEN_GLOW)
	{
		buf[pixel] = (unsigned char)(0);
		buf[pixel + 1] = (unsigned char)(iters * 255 * 10);
		buf[pixel + 2] = (unsigned char)(0);
		buf[pixel + 3] = (unsigned char)0;
	}
	if (color == BLUE_GLOW)
	{
		buf[pixel] = (unsigned char)(iters * 255 * 10);
		buf[pixel + 1] = (unsigned char)(0);
		buf[pixel + 2] = (unsigned char)(0);
		buf[pixel + 3] = (unsigned char)0;
	}
}

void	solid(unsigned char color, unsigned int pixel, unsigned char iters,
		char *buf)
{
	color = 0;
	buf[pixel] = (unsigned char)(iters * 255);
	buf[pixel + 1] = (unsigned char)(iters * 255);
	buf[pixel + 2] = (unsigned char)(iters * 255);
	buf[pixel + 3] = (unsigned char)0;
}
