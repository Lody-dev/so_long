#include "./utils/so_long.h"
int main(void)
{
	int	map_size;
	int i;
	char	**map;
	
	map_size = map_size_count();
	printf("Map size is: %d\n", map_size);
	map = map_init(map_size); //DO NOT FORGET TO FREE MAP !!!LEAKS!!!
	
	i = 0;
	while (i < map_size)  // Assumes map is null-terminated
	{
		printf("%s", map[i]);  // Print the string at map[i]
		i++;  // Move to the next element
	}
	if (is_map_rectangular(map, map_size) == -1)
		return (printf("Map reading KO!\n"), -1);
	if (are_walls_ok(map, map_size) == -1)
		return (printf("Walls KO!\n"), -1);

}
