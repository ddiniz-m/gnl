/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:48:39 by ddiniz-m          #+#    #+#             */
/*   Updated: 2022/11/28 10:20:09 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	res[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
	{
		while (fd >= 0 && fd < FOPEN_MAX && res[fd][i])
			res[fd][i] = 0;
		return (NULL);
	}
	line = NULL;
	while (res[fd][0] || read(fd, res[fd], BUFFER_SIZE) > 0)
	{
		line = get_lines(line, res[fd]);
		if (check_next_line(res[fd]))
			break ;
	}
	return (line);
}

/* int	main(void)
{
	int fd1;
	int fd2;
	int fd3;
	char *line;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd1);
		if (line == NULL)
			break ;
		printf("%s", line);
		line = get_next_line(fd2);
		if (line == NULL)
			break ;
		printf("%s", line);
		line = get_next_line(fd3);
		if (line == NULL)
			break ;
		printf("%s", line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */