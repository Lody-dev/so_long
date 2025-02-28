/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsarmien <dsarmien@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:47:00 by dsarmien          #+#    #+#             */
/*   Updated: 2025/02/17 13:10:44 by dsarmien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nlibft.h"

int	ft_write_nbr_fd(int n, int fd)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putstr_fd("-2147483648", fd);
		return (len);
	}
	if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		len += ft_write_nbr_fd(n / 10, fd);
	len += ft_putchar_fd("0123456789"[n % 10], fd);
	return (len);
}

int	ft_write_unbr_fd(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_write_unbr_fd(n / 10, fd);
	len += ft_putchar_fd("0123456789"[n % 10], fd);
	return (len);
}

/* int	main(void)
{
	ft_write_nbr(-42);
	// Expected output: -42
	// Expected return: 2
	ft_write_unbr(4242)
	// Expected output: 4242
	// Expected return: 4
	return (0);
} */

int	ft_write_hex_fd(unsigned long long n, char letter, int fd)
{
	char	*base;
	char	buffer[16];
	int		i;
	int		len;

	if (letter == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	len = 0;
	if (n == 0)
		buffer[i++] = '0';
	while (n > 0)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	len = i;
	while (i > 0)
		ft_putchar_fd(buffer[--i], fd);
	return (len);
}

/* int	main(void)
{
	ft_write_hex(0x2f, 'x');
	write(1, "\n", 1);
	// Expected output: 2f
	// Expected return: 2
	ft_write_hex(0x2F, 'X');
	// Expected output: 2F
	// Expected return: 2
	ft_write_hex(0x4abc, 'x');
	// Expected output: 4abc
	// Expected return: 4
	return (0);
} */

int	ft_write_ptr_fd(unsigned long long ptr, int fd)
{
	int	addr;

	if (!ptr)
		return (ft_putstr_fd("(nil)", fd));
	addr = 0;
	addr += ft_putstr_fd("0x", fd);
	addr += ft_write_hex_fd(ptr, 'x', fd);
	return (addr);
}

/* int	main(void)
{
	// unsigned long long ptr = 0x1234abcd;
	// ft_write_ptr(ptr);
	// Expected output: 1234abcd
	// Expected return: 8
	printf("%p", NULL);
	return (0);
} */