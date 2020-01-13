/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 22:19:11 by twakrim           #+#    #+#             */
/*   Updated: 2019/10/02 21:59:01 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# define BUFF_SIZE 10000
# define BK_SLSHN_POS pos[0]
# define READ_VAL pos[1]
# define F_LINE_LEN pos[2]
# define ZOOM 5

typedef struct		s_save
{
	int				fd;
	char			*data;
	struct s_save	*next;
}					t_save;

typedef struct		s_table
{
	int				altitude;
	int				color;
}					t_table;

typedef struct		s_cord
{
	int				x;
	int				y;
}					t_cord;

typedef struct		s_info
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				z1;
	int				z2;
	int				stepx;
	int				stepy;
	int				p;
	int				abs;
	int				ord;
	int				dx;
	int				dy;
	void			*mlx_ptr;
	void			*win_ptr;
	char			*s;
	t_table			**cords;
}					t_info;

void				freecords(t_table **table, t_cord length);

void				partie_deux(t_cord i, t_cord l, t_info *b, t_table **tab);

void				partie_un(t_cord x, t_cord length, t_info *b);

void				positioner_et_zoomer_un(t_info *b, int i, int j);

void				positioner_et_zoomer_deux(t_info *b, int i, int j);

void				partie2_bres(t_info *b);

void				partie1_bres(t_info *b);

int					deal_key(int key, t_info *b);

void				bres(t_info *b);

void				iso(int *x, int *y, int z);

void				projection_un(void *mlx, void *win, t_cord s);

void				projection_deux(void *mx, void *wx, t_cord l, t_table **t);

int					lenlign(char *s);

int					lenfile(char *s);

int					get_file_lines(const int fd, char **line);

int					reader(char **s, char *filename);

int					valfile(char *s);

int					collecting_data(char **s, char *filename, t_table ***cords);

#endif
