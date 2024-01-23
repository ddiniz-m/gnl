/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:48:42 by ddiniz-m          #+#    #+#             */
/*   Updated: 2022/11/18 03:15:46 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

int	check_next_line(char *res)
{
	int	i;
	int	n;
	int	j;

	i = 0;
	n = 0;
	j = 0;
	while (res[i])
	{
		if (n == 1)
			res[j++] = res[i];
		if (res[i] == '\n')
			n = 1;
		res[i++] = '\0';
	}
	return (n);
}

char	*get_lines(char *line, char *res)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(res) + 1));
	while (line && line[i])
	{
		temp[i] = line[i];
		i++;
	}
	while (*res)
	{
		temp[i++] = *res;
		if (*res++ == '\n')
			break ;
	}
	temp[i] = '\0';
	free(line);
	return (temp);
}
