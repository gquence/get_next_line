#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
int	main()
{
	int	fd;
	char *line;

	fd = open("wap.c", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s", line);
		free (line);
	}
	return (0);
}
