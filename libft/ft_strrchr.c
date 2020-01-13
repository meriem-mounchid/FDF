/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <taha.wakrim.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:43:09 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/17 22:30:49 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cherchedchar;
	char	*str;

	str = (char *)s;
	i = ft_strlen(str);
	cherchedchar = (char)c;
	while (i >= 0)
	{
		if (str[i] == cherchedchar)
		{
			return (str + i);
		}
		i--;
	}
	if (cherchedchar == '\0')
		return (str + ft_strlen(str));
	return (NULL);
}
