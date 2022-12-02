/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:48:39 by ddiniz-m          #+#    #+#             */
/*   Updated: 2022/12/02 18:30:28 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	res[BUFFER_SIZE + 1];
	char		*line;

	if (read(fd, NULL, 0) < 0)
	{
		*res = 0;
		return (NULL);
	}
	line = NULL;
	while (res[0] || read(fd, res, BUFFER_SIZE) > 0)
	{
		line = get_lines(line, res);
		if (check_next_line(res))
			break ;
	}
	return (line);
}

/* int	main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	printf("%d\n", fd);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
	}
	close(fd);
	return (0);
} */