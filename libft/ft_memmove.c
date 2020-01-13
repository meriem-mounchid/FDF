/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <taha.wakrim.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:29:14 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/28 01:16:38 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*adsrc;
	char		*dest;
	size_t		i;

	i = 0;
	adsrc = (char *)src;
	dest = (char *)dst;
	if (dest > adsrc)
		while (++i <= len)
			dest[len - i] = adsrc[len - i];
	else
		while (i < len)
		{
			dest[i] = adsrc[i];
			i++;
		}
	return (dst);
}
