#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	main()
{
	const int count = 1000000000;
	int fd = open("txt.txt", O_WRONLY);

	for (int i = 0; i < count; i++)
	{
		write(fd, "\n", 1);
	}
	
}
