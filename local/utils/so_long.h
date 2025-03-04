#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char **map_init(int map_size);
int map_size_count(void);
int is_map_rectangular(char **map, int map_size);
int line_check(char* line);
int are_walls_ok(char **map, int map_size);

#endif // SO_LONG_H

