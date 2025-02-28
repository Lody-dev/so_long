/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsarmien <dsarmien@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:25:20 by dsarmien          #+#    #+#             */
/*   Updated: 2025/01/09 14:57:00 by dsarmien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nlibft.h"

/**
 * @brief Checks if a base is valid.
 * 
 * 		  - It has 2 or more elements.
 *
 * 		  - It does not contain repeated elements.
 *
 * 		  - It does not contain a sign ('-' or '+').
 *
 * @param base Pointer to the base symbols.
 * @return 1 if it's a valid base; 0 otherwise.
 */
static int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!*base || !*(base + 1))
		return (0);
	i = 0;
	while (base[i])
	{
		if (ft_sign(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < -9 || n > 9)
		ft_putnbr_fd(n / 10, fd);
	if (n < 0)
	{
		if (n >= -9)
			ft_putchar_fd('-', fd);
		ft_putchar_fd('0' - (n % 10), fd);
	}
	else
		ft_putchar_fd('0' + (n % 10), fd);
}

/* ADDITIONAL AND USEFUL FUNCTIONS NOT IN THE MAIN PROJECT */

/**
 * @brief	Writes the number 'n' to the given file descriptor.
 * @param n The integer to write.
 * @param fd The file descriptor on which to write.
 * @return	The number of characters written (in this case, digits).
 */
/* int	ft_putnbr_fd_v2(long long n, int fd)
{
	return (ft_putnbr_base_fd(n, "0123456789", fd));
} */

int	ft_putnbr_base_fd(long long n, char *base, int fd)
{
	size_t	len;

	if (!is_valid_base(base))
		return (0);
	len = 0;
	if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		n *= 1;
	}
	return (len + ft_putunbr_base_fd(n, base, fd));
}

int	ft_putunbr_fd(unsigned long long n, int fd)
{
	return (ft_putunbr_base_fd(n, "0123456789", fd));
}

int	ft_putunbr_base_fd(unsigned long long n, char *base, int fd)
{
	char				c;
	size_t				len;
	unsigned long long	b;

	if (!is_valid_base(base))
		return (0);
	len = 0;
	b = ft_strlen(base);
	if (b - 1 < n)
		len += ft_putunbr_base_fd(n / b, base, fd);
	c = base[n % b];
	len += ft_putchar_fd(c, fd);
	return (len);
}
