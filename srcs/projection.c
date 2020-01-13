/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:00:21 by mmounchi          #+#    #+#             */
/*   Updated: 2019/09/24 16:36:04 by mmounchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	partie_deux(t_cord i, t_cord length, t_info *b, t_table **table)
{
	if (i.y + 1 < length.x)
	{
		positioner_et_zoomer_un(b, i.x, i.y);
		iso(&b->x1, &b->y1, table[i.y][i.x].altitude);
		iso(&b->x2, &b->y2, table[i.y + 1][i.x].altitude);
		bres(b);
	}
	if (i.x + 1 < length.y)
	{
		positioner_et_zoomer_deux(b, i.x, i.y);
		iso(&b->x1, &b->y1, table[i.y][i.x].altitude);
		iso(&b->x2, &b->y2, table[i.y][i.x + 1].altitude);
		bres(b);
	}
}

void	partie_un(t_cord c, t_cord length, t_info *b)
{
	if (c.y + 1 < length.x)
	{
		positioner_et_zoomer_un(b, c.x, c.y);
		bres(b);
	}
	if (c.x + 1 < length.y)
	{
		positioner_et_zoomer_deux(b, c.x, c.y);
		bres(b);
	}
}

void	projection_un(void *mlx, void *win, t_cord length)
{
	t_info	b;
	int		i;
	int		j;
	t_cord	x;

	b.mlx_ptr = mlx;
	b.win_ptr = win;
	i = 0;
	while (i < length.y)
	{
		j = 0;
		while (j < length.x)
		{
			x.x = i;
			x.y = j;
			partie_un(x, length, &b);
			j++;
		}
		i++;
	}
}

void	projection_deux(void *mlx, void *win, t_cord length, t_table **table)
{
	t_info	b;
	int		i;
	int		j;
	t_cord	c;

	b.mlx_ptr = mlx;
	b.win_ptr = win;
	i = 0;
	while (i < length.y)
	{
		j = 0;
		while (j < length.x)
		{
			c.x = i;
			c.y = j;
			partie_deux(c, length, &b, table);
			j++;
		}
		i++;
	}
}

int		deal_key(int key, t_info *b)
{
	t_cord x;

	if (key == 53)
		exit(1);
	x.x = lenfile(b->s);
	x.y = lenlign(b->s);
	if (key == 35)
	{
		mlx_clear_window(b->mlx_ptr, b->win_ptr);
		projection_un(b->mlx_ptr, b->win_ptr, x);
	}
	else if (key == 34)
	{
		mlx_clear_window(b->mlx_ptr, b->win_ptr);
		projection_deux(b->mlx_ptr, b->win_ptr, x, b->cords);
	}
	return (0);
}
