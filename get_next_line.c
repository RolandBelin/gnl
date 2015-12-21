/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbelin <rbelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 07:55:56 by rbelin            #+#    #+#             */
/*   Updated: 2015/12/07 17:23:47 by rbelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static void	ft_gnlcpy(char *dest, const char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
	       ++i;	
	}
	if (i < BUFF_SIZE)
		dest[i] = '\0';
}

static void	ft_gnlcat(char *dst, const char *buff, int size)
{
	unsigned int	endline;
	int		i;

	i = 0;
	while (dst[endline])
		++endline;
	while (i < size)
	{
		dst[endline] = buff[i];
		++i;
		++endline;
	}
	dst[endline] = '\0';
}

static char	ft_applybuff(char **line, char *buff, char *save, int size)
{
	int	i;

	i = 0;
	if (size == 0)
		return (1);
	while (i < size && buff[i] != '\n')
		++i;
	if (buff[i] == '\n')
	{
		ft_gnlcpy(save, &buff[i + 1], BUFF_SIZE - (i + 1));
		ft_gnlcat(*line, buff, i);
		return (1);
	}
	ft_gnlcat(*line, buff, size);
	return (0);
}

static char	ft_applysave(char **line, char *save)
{
	int	i;

	i = 0;
	if (save[0] == '\0')
		return (0);
	while (i < BUFF_SIZE && save[i] && save[i] != '\n')
		++i;
	ft_gnlcat(*line, save, i);
	if (save[i] == '\n')
	{
		ft_gnlcpy(save, &save[i + 1], BUFF_SIZE - (i + 1));
		return (1);
	}
	i = 0;
	while (i < BUFF_SIZE)
	{
		save[i] = '\0';
		return (0);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	save[BUFF_SIZE];
	char		buff[BUFF_SIZE];
	int		readreturn;

	readreturn = 0;
	if (ft_applysave(line, save))
		return (1);
	while ((readreturn = read(fd, buff, BUFF_SIZE)) &&
		!ft_applybuff(line, buff, save, readreturn))
		;
	if (readreturn > -1)
		return ((readreturn > 0) ? 1 : 0);
	return (-1);
}
