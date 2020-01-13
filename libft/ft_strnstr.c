/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 21:55:43 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/26 15:18:52 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char *)haystack;
	str2 = (char *)needle;
	while (str1[i] != '\0' && i < len)
	{
		j = 0;
		while (str1[i + j] == str2[j] && (i + j) < len && str2[j] != '\0')
			j++;
		if (str2[j] == '\0')
			return (str1 + i);
		i++;
	}
	return (NULL);
}
