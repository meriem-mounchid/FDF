/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <taha.wakrim.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:20:21 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/28 01:16:14 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	int			checker;
	const char	*ccpysrc;
	char		*ccpydst;
	char		inttochar;

	i = 0;
	inttochar = (char)c;
	checker = 0;
	ccpysrc = src;
	ccpydst = dst;
	while (i < n)
	{
		ccpydst[i] = ccpysrc[i];
		if (ccpysrc[i] == inttochar)
		{
			checker = 1;
			break ;
		}
		i++;
	}
	if (checker == 0)
		return (NULL);
	i++;
	return (ccpydst + i);
}
