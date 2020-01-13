/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewmatrice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:53:07 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/23 14:54:50 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strnewmatrice(size_t size)
{
	size_t	i;
	char	**str;

	i = 0;
	str = (char**)malloc(sizeof(char*) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i <= size)
	{
		str[i] = "\0";
		i++;
	}
	return (str);
}
