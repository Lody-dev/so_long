/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsarmien <dsarmien@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 00:02:14 by dsarmien          #+#    #+#             */
/*   Updated: 2024/11/05 20:05:52 by dsarmien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nlibft.h"

static int	ft_process_flag(va_list *args, const char letter, int fd)
{
	int	printed;

	printed = 0;
	if (letter == 'c')
		printed += ft_putchar_fd(va_arg(*args, int), fd);
	else if (letter == 's')
		printed += ft_putstr_fd(va_arg(*args, char *), fd);
	else if (letter == 'p')
		printed += ft_write_ptr_fd(va_arg(*args, unsigned long long), fd);
	else if ((letter == 'd') || (letter == 'i'))
		printed += ft_write_nbr_fd(va_arg(*args, int), fd);
	else if (letter == 'u')
		printed += ft_write_unbr_fd(va_arg(*args, unsigned int), fd);
	else if (letter == 'x' || letter == 'X')
		printed += ft_write_hex_fd(va_arg(*args, unsigned int), letter, fd);
	else if (letter == '%')
		printed += ft_putchar_fd(letter, fd);
	else
		printed += ft_putchar_fd(letter, fd);
	return (printed);
}

/*
The accepted format specifiers are:
- %c: Print a single character.
- %s: Print a string of characters.
- %p: Print a pointer address.
- %d: Print a decimal number.
- %i: Print an integer in base 10.
- %u: Print an unsigned decimal number.
- %x: Print a number in hexadecimal using [a-f].
- %X: Print a number in hexadecimal using [A-F].
- %%: Print a percent sign.
*/

int	ft_printf(int fd, const char *format, ...)
{
	int		i;
	int		printed;
	va_list	args;

	i = 0;
	printed = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			printed += ft_process_flag(&args, format[i + 1], fd);
			i++;
		}
		else
			printed += ft_putchar_fd(format[i], fd);
		i++;
	}
	va_end(args);
	return (printed);
}
