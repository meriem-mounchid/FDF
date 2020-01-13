/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:39:42 by twakrim           #+#    #+#             */
/*   Updated: 2019/08/11 15:39:52 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_save		*init(t_save *head, int fd, char **f_line)
{
	t_save	*curent;
	int		pos;

	curent = head;
	pos = 0;
	*f_line = NULL;
	if (curent == NULL)
	{
		curent = (t_save *)malloc(sizeof(t_save));
	}
	else
	{
		while (curent->next || curent->fd == fd)
		{
			if (curent->fd == fd)
				return (curent);
			curent = curent->next;
		}
		curent->next = (t_save *)malloc(sizeof(t_save));
		curent = curent->next;
	}
	curent->fd = fd;
	curent->data = NULL;
	curent->next = NULL;
	return (curent);
}

char		*set_saved_part(t_save *curent, char *f_line)
{
	if (curent->data != NULL)
	{
		f_line = ft_strdup(curent->data);
		free(curent->data);
	}
	else
		f_line = ft_strdup("");
	return (f_line);
}

char		*read_line(int fd, char *buff, char *f_line, int *pos)
{
	char			*temp;

	BK_SLSHN_POS = 0;
	while ((READ_VAL = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[READ_VAL] = '\0';
		temp = f_line;
		f_line = ft_strjoin(f_line, buff);
		free(temp);
		if (ft_strchr(f_line, '\n') != NULL)
		{
			F_LINE_LEN = ft_strlen(f_line);
			return (f_line);
		}
	}
	F_LINE_LEN = ft_strlen(f_line);
	return (f_line);
}

int			return_value(char **f_line, int *pos)
{
	free(*f_line);
	if (F_LINE_LEN == 0 && READ_VAL == 0)
		return (0);
	return (1);
}

int			get_file_lines(const int fd, char **line)
{
	static t_save	*head;
	t_save			*curent;
	char			*f_line;
	int				pos[3];
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	if (head == NULL)
	{
		head = init(head, fd, &f_line);
		curent = head;
	}
	else
		curent = init(head, fd, &f_line);
	f_line = set_saved_part(curent, f_line);
	f_line = read_line(fd, buff, f_line, pos);
	while (f_line[BK_SLSHN_POS] != '\n' && f_line[BK_SLSHN_POS] != '\0')
		BK_SLSHN_POS++;
	if (F_LINE_LEN != 0)
		curent->data = ft_strsub(f_line, pos[0] + 1,
			ft_strlen(f_line) - BK_SLSHN_POS);
	*line = ft_strsub(f_line, 0, BK_SLSHN_POS + 1);
	return (return_value(&f_line, pos));
}
