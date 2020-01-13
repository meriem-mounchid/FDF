/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 22:18:10 by twakrim           #+#    #+#             */
/*   Updated: 2019/10/02 20:03:19 by mmounchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	splittocords(t_table ***cords, char *twodfile, int a)
{
	char	**s;
	int		i;
	int		c;

	s = ft_strsplit(twodfile, ' ');
	i = 0;
	c = lenlign(twodfile);
	while (i < c)
	{
		(cords[0][a][i]).altitude = ft_atoi(s[i]);
		i++;
	}
}

int		reader(char **s, char *filename)
{
	int		fd;
	int		ret;
	int		len;
	char	*line;
	char	*temp;

	len = 0;
	*s = ft_strdup("");
	(fd = open(filename, O_RDONLY));
	while ((ret = get_file_lines(fd, &line)) > 0)
	{
		temp = *s;
		*s = ft_strjoin(*s, line);
		free(line);
		free(temp);
	}
	len = ft_strlen(*s);
	if (ret < 0)
		return (0);
	free(line);
	return (1);
}

int		collecting_data(char **s, char *filename, t_table ***cords)
{
	int		fd;
	int		ret;
	t_cord	len;
	char	*line;
	char	*temp;

	len.x = 0;
	len.y = 0;
	*s = ft_strdup("");
	(fd = open(filename, O_RDONLY));
	while ((ret = get_file_lines(fd, &line)) > 0)
	{
		temp = *s;
		*s = ft_strjoin(*s, line);
		splittocords(cords, line, len.y);
		free(line);
		free(temp);
		len.y++;
	}
	len.x = ft_strlen(*s);
	if (ret < 0)
		return (0);
	free(line);
	return (1);
}

void	positioner_et_zoomer_un(t_info *b, int i, int j)
{
	b->x1 = i * ZOOM;
	b->y1 = j * ZOOM;
	b->x2 = i * ZOOM;
	b->y2 = (j + 1) * ZOOM;
}

void	positioner_et_zoomer_deux(t_info *b, int i, int j)
{
	b->x1 = i * ZOOM;
	b->y1 = j * ZOOM;
	b->x2 = (i + 1) * ZOOM;
	b->y2 = j * ZOOM;
}
