/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <taha.wakrim.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 18:02:58 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/18 09:26:40 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char *)haystack;
	str2 = (char *)needle;
	if (*str2 == '\0' && *str1 == '\0')
		return (str1);
	while (str1[i] != '\0')
	{
		j = 0;
		while (str1[i + j] == str2[j] && str2[j] != '\0')
			j++;
		if (str2[j] == '\0')
			return (str1 + i);
		i++;
	}
	return (NULL);
}
