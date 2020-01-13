/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:32:28 by mmounchi          #+#    #+#             */
/*   Updated: 2019/09/28 14:44:42 by mmounchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	partie2_bres(t_info *b)
{
	int i;

	i = 0;
	b->p = 2 * b->dx - b->dy;
	while (i < b->dy)
	{
		b->ord += b->stepy;
		if (b->p < 0)
			b->p = b->p + 2 * b->dx;
		else
		{
			b->p = b->p + 2 * b->dx - 2 * b->dy;
			b->abs += b->stepx;
		}
		mlx_pixel_put(b->mlx_ptr, b->win_ptr, b->abs +
			900, b->ord + 200, 0xFF0000);
		i++;
	}
}

void	partie1_bres(t_info *b)
{
	int i;

	i = 0;
	b->p = 2 * b->dy - b->dx;
	while (i < b->dx)
	{
		b->abs += b->stepx;
		if (b->p < 0)
			b->p = b->p + 2 * b->dy;
		else
		{
			b->p = b->p + 2 * b->dy - 2 * b->dx;
			b->ord += b->stepy;
		}
		mlx_pixel_put(b->mlx_ptr, b->win_ptr, b->abs +
			900, b->ord + 200, 0xFFFFFF);
		i++;
	}
}

void	bres(t_info *b)
{
	int i;

	i = 0;
	b->abs = b->x1;
	b->ord = b->y1;
	mlx_pixel_put(b->mlx_ptr, b->win_ptr, b->x1 + 900, b->y1 + 200, 0xFFFFFF);
	b->dx = b->x2 - b->x1;
	b->dy = b->y2 - b->y1;
	if (b->dx > 0)
		b->stepx = 1;
	else
		b->stepx = -1;
	if (b->dy > 0)
		b->stepy = 1;
	else
		b->stepy = -1;
	b->dx = abs(b->dx);
	b->dy = abs(b->dy);
	if (b->dx > b->dy)
		partie1_bres(b);
	else
		partie2_bres(b);
}

void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	freecords(t_table **table, t_cord length)
{
	int		i;

	i = 0;
	while (i < length.x)
	{
		free(table[i]);
		i++;
	}
	free(table);
}
