#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
		return 0;
	
	int res;
	char **line = malloc(1);
	int *fd = malloc(4 * (argc - 1));
	int i = 0;

	while (++i < argc)
		fd[i - 1] = open(argv[i], O_RDONLY);
	while (--i)
	{
		while ((res = get_next_line(fd[i - 1], line)) == 1)
		{
			printf("[%d] ||| %s |||%s\n", res, *line, argv[i]);
			if (i == 3)
				i = 4;
			else if (i == 4)
				i = 3;
		}
		printf("[%d] ||| %s ||| %s\n", res, *line, argv[i]);
		close(fd[i - 1]);
	}
	return 0;
}