/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsarmien <dsarmien@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:19:12 by dsarmien          #+#    #+#             */
/*   Updated: 2024/10/17 17:38:24 by dsarmien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nlibft.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	size_t	s_len;

	if (!s)
		s = "(null)";
	s_len = ft_strlen(s);
	write(fd, s, s_len);
	return (s_len);
}

int	ft_putendl_fd(char *s, int fd)
{
	size_t	s_len;

	s_len = 0;
	s_len += ft_putstr_fd(s, fd);
	s_len += ft_putchar_fd('\n', fd);
	return (s_len + 1);
}
