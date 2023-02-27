/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:53:40 by lsileoni          #+#    #+#             */
/*   Updated: 2022/11/02 07:11:20 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned char	arr[10];
	long int		n_long;

	n_long = n;
	if (!n)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n_long < 0)
	{
		ft_putchar_fd('-', fd);
		n_long *= -1;
	}
	n = 0;
	while (n_long)
	{
		arr[n] = (n_long % 10) + 48;
		n_long /= 10;
		n++;
	}
	while (n--)
		ft_putchar_fd(arr[n], fd);
}
