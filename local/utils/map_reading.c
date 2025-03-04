/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viaremko <viaremko@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:32:10 by viaremko          #+#    #+#             */
/*   Updated: 2024/12/03 20:29:58 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char **map_init(int map_size)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	map = (char **)malloc(map_size * sizeof(char*)); //DO NOT FORGET TO FREE MAP
	if(!map)
		return(NULL);	
	fd = open("map", O_RDONLY);
	if (fd == -1)
	{
		printf("Error reading!\n");
		return (NULL);
	}
	else
	{
		i = -1;
		while ((line = get_next_line(fd)) != NULL)
		{
			map[++i] = line;
		}
	}
	// DO NOT FOREGET TO ADD NULL TERMINATOR TO MAP
	close(fd);
	return (map);
}

int	map_size_count(void)
{
	int	i;
	int		fd;
	char	*line;

	fd = open("map", O_RDONLY);
	if (fd == -1)
	{
		printf("Error reading!\n");
		return (1);
	}
	else
	{
		i = 0;
		while ((line = get_next_line(fd)) != NULL)
		{
			i++;
			free(line);
		}
		free(line);
	}
	close(fd);
	return (i);
}

int is_map_rectangular(char **map, int map_size)
{
	int i;
	int first_line_lenth;
	int current_line_lenth;
	
	i = 0;
	first_line_lenth = ft_strlen(map[i]);
	while(i < map_size)
	{
		current_line_lenth = ft_strlen(map[i]);
		if(current_line_lenth == first_line_lenth)
			i++;
		else
			return(-1);		
	}
	return (first_line_lenth);
}

int line_check(char* line)
{
	int i;
	i = 0;
		
	while(line[i] != '\0')
	{
		if(line[i] == '1')
			i++;
		else
			return(-1);
	}
	return(i);	
}

int are_walls_ok(char **map, int map_size)
{
	if(line_check(map[0]) == -1 && line_check(map[map_size]) == -1)
		return(-1);
	return(1);
}
