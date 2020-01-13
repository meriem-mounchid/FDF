/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 18:07:07 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/23 14:05:04 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;

	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	if (s && len > 0)
		ft_strncat(str, s + start, len);
	return (str);
}
