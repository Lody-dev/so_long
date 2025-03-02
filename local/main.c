/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsarmien <dsarmien@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:32:10 by dsarmien          #+#    #+#             */
/*   Updated: 2024/12/03 20:29:58 by dsarmien         ###   ########.fr       */
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
	fd = open("tester", O_RDONLY);
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

	fd = open("tester", O_RDONLY);
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
			printf("%s", line);
			free(line);
		}
		free(line);
	}
	close(fd);
	return (i);
}

int main(void)
{
	int	map_size;
	//int i;
	char	**map;
	
	map_size = map_size_count();
	printf("Map size is: %d\n", map_size);
	map = map_init(map_size); //DO NOT FORGET TO FREE MAP !!!LEAKS!!!
	
	/*
	i = 0;
	while (i < map_size)  // Assumes map is null-terminated
	{
		printf("%s", map[i]);  // Print the string at map[i]
		i++;  // Move to the next element
	}
	*/

}
