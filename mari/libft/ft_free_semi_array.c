#include "libft.h"

void ft_free_semi_array(char **array, int c)
{
	int	i;

	i = 0;
	if (!array)
		return;
	while (i < c)
		free(array[i++]);
	free(array);
}
