/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 06:48:24 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/27 21:07:35 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*strnmb;

	strnmb = NULL;
	i = ft_calcnumb(n) - 1;
	j = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(strnmb = ft_strnew(i + 1)))
		return (NULL);
	if (n < 0)
	{
		strnmb[j++] = '-';
		n *= -1;
	}
	while (j <= i)
	{
		strnmb[i--] = n % 10 + 48;
		n = n / 10;
	}
	return (strnmb);
}
