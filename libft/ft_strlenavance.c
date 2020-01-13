/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenavance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 05:28:37 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/26 19:38:51 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlenavance(char *str, int beginindex, char splitchar)
{
	int		i;

	i = beginindex;
	while (str[i] && str[i] != splitchar && str[i] != '\0')
		i++;
	return (i - beginindex);
}
