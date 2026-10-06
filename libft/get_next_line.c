/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:21:31 by jemoreir          #+#    #+#             */
/*   Updated: 2025/11/05 15:51:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes;
	size_t		i;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		tmp = ft_substr_get(buffer, 0, i + (buffer[i] == '\n'));
		line = ft_strjoin_get(line, tmp);
		if (buffer[i] == '\n')
			return (ft_memcpy_get(buffer, buffer + i + 1, ft_len(buffer + i + 1)
					+ 1), line);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (ft_check_error_get(bytes, line, buffer));
		buffer[bytes] = '\0';
	}
}
