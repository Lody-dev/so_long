/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsarmien <dsarmien@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:30:02 by dsarmien          #+#    #+#             */
/*   Updated: 2025/01/09 14:29:37 by dsarmien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nlibft.h"

void	ft_create_file(char *filename, char *content)
{
	int	fd;

	if (!content || !*content)
		return ;
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return ;
	write(fd, content, ft_strlen(content));
	close(fd);
}
