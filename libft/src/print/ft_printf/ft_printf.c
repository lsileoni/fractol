/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:32:16 by lsileoni          #+#    #+#             */
/*   Updated: 2022/11/27 20:32:17 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_symbol(char symbol, va_list args)
{
	int	rval;

	rval = 0;
	if (symbol == 'c')
		rval += ft_i_putchar_fd(va_arg(args, int), 1);
	else if (symbol == 'd' || symbol == 'i')
		rval += print_number(va_arg(args, int));
	else if (symbol == 'u')
		rval += print_unumber(va_arg(args, unsigned int));
	else if (symbol == 's')
		rval += print_string(va_arg(args, char *));
	else if (symbol == 'p')
		rval += print_pointer(va_arg(args, unsigned long long));
	else if (symbol == 'x')
		rval += print_hex(va_arg(args, unsigned int), 0);
	else if (symbol == 'X')
		rval += print_hex(va_arg(args, unsigned int), 1);
	else if (symbol == '%')
		rval += ft_i_putchar_fd('%', 1);
	return (rval);
}

int	read_first_arg(char *first_arg, va_list args)
{
	int	rval;
	int	i;

	i = 0;
	rval = 0;
	while (first_arg[i])
	{
		if (first_arg[i] == '%')
		{
			i++;
			rval += do_symbol(first_arg[i], args);
			if (!first_arg[i + 1])
				break ;
		}
		else
			rval += ft_i_putchar_fd(first_arg[i], 1);
		i++;
	}
	return (rval);
}

int	ft_printf(const char *args, ...)
{
	va_list	arg_list;
	char	*first_arg;
	int		rval;

	if (!args)
		return (0);
	first_arg = ft_strdup(args);
	if (!first_arg)
		return (0);
	va_start(arg_list, args);
	rval = read_first_arg(first_arg, arg_list);
	va_end(arg_list);
	free(first_arg);
	return (rval);
}
