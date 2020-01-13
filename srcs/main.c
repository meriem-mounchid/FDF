/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:28:22 by twakrim           #+#    #+#             */
/*   Updated: 2019/10/02 20:06:17 by mmounchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		usage_error(int argc)
{
	if (argc != 2)
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
		exit(0);
	}
}

t_table		**mallocords(t_cord length)
{
	t_table		**cords;
	int			i;

	i = 0;
	cords = (t_table **)malloc(sizeof(t_table *) * (length.x));
	while (i < length.x)
	{
		cords[i] = (t_table *)malloc(sizeof(t_table ) * (length.y));
		i++;
	}
	return (cords);
}

int			lenlign(char *s)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		if (i == 0)
			while (s[i] == ' ' || s[i] == '\t')
				i++;
		if (s[i] == ' ' || s[i] == '\t')
			c++;
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		i++;
	}
	return (c + 1);
}

int			lenfile(char *s)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			c++;
		i++;
	}
	if (s[i - 1] != '\n')
		c++;
	return (c);
}

int			main(int argc, char **argv)
{
	t_info		b;
	t_cord		length;

	usage_error(argc);
	if (reader(&b.s, argv[1]) == 0)
	{
		ft_putstr("error\n");
		exit(0);
	}
	valfile(b.s);
	length.x = lenfile(b.s);
	length.y = lenlign(b.s);
	b.cords = mallocords(length);
	collecting_data(&b.s, argv[1], &b.cords);
	b.mlx_ptr = mlx_init();
	b.win_ptr = mlx_new_window(b.mlx_ptr, 2000, 2000, "fdf");
	projection_un(b.mlx_ptr, b.win_ptr, length);
	mlx_hook(b.win_ptr, 2, 0, &deal_key, &b);
	mlx_loop(b.mlx_ptr);
	freecords(b.cords, length);
	return (0);
}
