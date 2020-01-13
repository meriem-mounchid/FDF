/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:15:11 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/28 01:33:05 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*allmemo;

	allmemo = NULL;
	if (size > 0)
	{
		if (!(allmemo = (char *)malloc(sizeof(char) * size)))
			return (NULL);
	}
	ft_bzero(allmemo, size);
	return (allmemo);
}
