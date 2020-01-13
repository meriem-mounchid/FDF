/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <taha.wakrim.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:29:56 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/12 11:58:34 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*cpysrc;
	char		*cpydst;

	i = 0;
	cpysrc = src;
	cpydst = dst;
	while (i < n)
	{
		cpydst[i] = cpysrc[i];
		i++;
	}
	return (cpydst);
}
