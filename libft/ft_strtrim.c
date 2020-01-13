/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:55:13 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/27 01:46:00 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int				i;
	int				j;
	char			*str;
	unsigned char	*p;

	p = (unsigned char*)s;
	i = 0;
	if (s)
	{
		j = ft_strlen(s) - 1;
		while (p[i] == ' ' || p[i] == '\t' || p[i] == '\n')
			i++;
		while (p[j] == ' ' || p[j] == '\t'
				|| p[j] == '\n')
			j--;
		if (i > j)
			return (ft_strdup(""));
		str = ft_strsub(s, i, j - i + 1);
		return (str);
	}
	return (NULL);
}
