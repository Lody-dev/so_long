/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsarmien <dsarmien@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:18:54 by dsarmien          #+#    #+#             */
/*   Updated: 2024/10/17 14:47:48 by dsarmien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nlibft.h"

int	ft_toupper(int c)
{
	if (97 <= c && c <= 122)
	{
		return (c - 32);
	}
	return (c);
}

int	ft_tolower(int c)
{
	if (65 <= c && c <= 90)
	{
		return (c + 32);
	}
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	s1_len;
	size_t	s2_len;
	size_t	fn_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	fn_len = s1_len + s2_len;
	new = (char *) malloc(fn_len + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, s1_len);
	ft_memcpy(new + s1_len, s2, s2_len + 1);
	new[fn_len] = '\0';
	return (new);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
