/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:09:43 by twakrim           #+#    #+#             */
/*   Updated: 2019/10/02 20:01:48 by mmounchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		verifychar(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '\t' && s[i] != '\n' && s[i] != ','
			&& s[i] != ' ' && s[i] != '\0' && (s[i] <= '0'
			&& s[i] >= '9') && (s[i] <= 'a' && s[i] >= 'z')
			&& (s[i] <= 'A' && s[i] >= 'Z'))
			return (0);
		i++;
	}
	return (1);
}

int		verifylines2(char *s, int i, int first_line)
{
	int		c;

	c = 0;
	while (s[i] != '\0')
	{
		c = 0;
		while (s[i] != '\n' && s[i] != '\0')
		{
			if (s[i] != ' ' && s[i] != '\n' && s[i] != '\0')
				c++;
			while (s[i] != ' ' && s[i] != '\n' && s[i] != '\0')
				i++;
			i++;
		}
		if (c != first_line)
			return (0);
		i++;
	}
	return (1);
}

int		verifylines(char *s)
{
	int		first_line;
	int		i;

	i = 0;
	first_line = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\0')
			first_line++;
		while (s[i] != ' ' && s[i] != '\n' && s[i] != '\0')
			i++;
		i++;
	}
	if (verifylines2(s, i, first_line) == 1)
		return (1);
	else
		return (0);
}

int		verifyifnull(char *s)
{
	int		i;

	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] != ' ')
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int		valfile(char *s)
{
	if (verifyifnull(s) == 0)
	{
		ft_putstr("No data found.\n");
		exit(0);
	}
	if (verifychar(s) == 0)
	{
		ft_putstr("Inreadable character.\n");
		exit(0);
	}
	if (verifylines(s) == 0)
	{
		ft_putstr("Invalid lenght lines.\n");
		exit(0);
	}
	return (1);
}
