#include "cub3d.h"

int check_extension(char *filename)
{
	int len;

	len = ft_len(filename);
	if (!filename || len < 5)
	{
		printf("Error: Invalid File Name.\n");
		return (1);
	}
	if (filename[len - 4] != '.' || filename[len - 3] != 'c'
		|| filename[len - 2] != 'u' || filename[len - 1] != 'b')
		{
			printf("Error: Invalid File Name.\n");
			return (1);
		}
	return (0);
}

int count_lines(char *file)
{
	char *line;
	int r;
	int fd;

	fd = open(file, O_RDONLY);
	r = 0;
	if (fd < 0)
	{
		printf("Error: Cannot Open File.\n");
		return (0);
	}
	line = get_next_line(fd);
	while (line)
	{
		r++;
		free(line);
		line = get_next_line(fd);
	}
	printf("%i\n", r);
	return (r);
}

/* char *receive_map(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	return (NULL);
} */