#include "libft.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("tester", O_RDONLY);
	if (fd == -1)
	{
		printf("Error reading!̣\n");
		return (1);
	}
	else
	{
		while ((line = get_next_line(fd)) != NULL)
		{
			ft_printf(1, "%s", line);
			free(line);
		}
		free(line);
	}
	close(fd);
	return (0);
}
