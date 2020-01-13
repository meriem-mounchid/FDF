/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <taha.wakrim.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:10:29 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/28 01:16:50 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*newstr;

	i = 0;
	newstr = (char *)s;
	while (i < n)
	{
		if ((unsigned char)newstr[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
