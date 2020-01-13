/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gt_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:42:00 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/27 01:45:45 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char				*str;
	unsigned int		i;

	if (s && f)
	{
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (str == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = (f)(s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
