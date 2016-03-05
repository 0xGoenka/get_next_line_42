/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:27:39 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/05 14:03:33 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		alpha(char **line, char **stat)
{
	char *tmp;

	if (ft_strchr(*line, '\n'))
	{
		*stat = ft_strdup(ft_strchr(*line, '\n') + 1);
		tmp = ft_strsub(*line, 0, ft_strchr(*line, '\n') - *line);
		free(*line);
		*line = tmp;
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char *stat = NULL;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (stat)
	{
		*line = ft_strdup(stat);
		if (alpha(line, &stat))
			return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
		if (alpha(line, &stat))
			return (1);
	}
	*line = NULL;
	if (ret < 0)
		return (-1);
	return (0);
}
