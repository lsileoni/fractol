/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsileoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:10:23 by lsileoni          #+#    #+#             */
/*   Updated: 2023/01/06 14:36:35 by lsileoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../../libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *args, ...);
int		print_hex(unsigned int n, unsigned char uppercase);
int		print_pointer(unsigned long long pval);
int		print_string(char *s);
int		print_unumber(unsigned int n);
int		print_number(int n);

#endif
