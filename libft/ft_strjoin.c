/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 18:56:42 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/28 01:38:02 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strcatv;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	strcatv = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
				+ 1));
	if (strcatv == NULL)
		return (NULL);
	while (s1[i])
	{
		strcatv[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		strcatv[i + j] = s2[j];
		j++;
	}
	strcatv[i + j] = '\0';
	return (strcatv);
}
