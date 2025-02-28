/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int2str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsarmien <dsarmien@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:54:04 by dsarmien          #+#    #+#             */
/*   Updated: 2025/02/17 13:06:40 by dsarmien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nlibft.h"

// Should be Static for Francinette

int	ft_intlen(int n)
{
	int	n_len;

	n_len = 0;
	if (n <= 0)
		n_len++;
	while (n)
	{
		n /= 10;
		n_len++;
	}
	return (n_len);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (ft_sign(*str))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	n_len;
	long	nb;

	n_len = ft_intlen(n);
	nb = (long)n;
	str = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[n_len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		str[--n_len] = '0' + nb % 10;
		nb /= 10;
	}
	return (str);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (ft_sign(*str))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
