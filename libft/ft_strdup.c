/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <taha.wakrim.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 20:06:59 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/29 18:48:24 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*ch;

	ch = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (ch == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ch[i] = s1[i];
		i++;
	}
	ch[i] = '\0';
	return (ch);
}
