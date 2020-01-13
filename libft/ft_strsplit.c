/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 06:47:56 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/27 21:20:49 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		firstindex(const char *str, int c, int sn)
{
	int		i;

	i = sn;
	while (str[i] == c)
		i++;
	return (i);
}

static int		lastindex(const char *str, int c, int sn)
{
	int		i;

	i = sn;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		words;
	int		j;
	int		sn;
	int		endin;
	char	**str;

	if (!s)
		return (NULL);
	words = ft_calcwords(s, c);
	if (!(str = ft_strnewmatrice(words)))
		return (NULL);
	j = 0;
	sn = j;
	while (words > j)
	{
		sn = firstindex(s, c, sn);
		endin = lastindex(s, c, sn);
		str[j] = ft_strsub(s, sn, endin - sn);
		sn = endin + 1;
		j++;
	}
	str[j] = NULL;
	return (str);
}
