/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <taha.wakrim.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:28:27 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/28 01:18:26 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cherchedchar;
	char	*str;

	i = 0;
	str = (char *)s;
	cherchedchar = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == cherchedchar)
		{
			return (str + i);
		}
		i++;
	}
	if (cherchedchar == '\0')
		return (str + i);
	return (NULL);
}
