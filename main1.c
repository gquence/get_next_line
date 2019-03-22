
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int				main(void)
{
		char *buf;
		int handle,bytes;
		int	i;

		if(!(handle = open("wap.c", O_RDONLY)))
		{
			printf("Ошибка при открытии файла.\n");
			return 0;
		}
		while(get_next_line(handle, &buf))
			printf("%s", buf);
		return (0);
}
