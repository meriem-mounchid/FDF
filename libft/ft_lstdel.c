/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:46:48 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/26 21:20:40 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*newlst;

	if (alst)
	{
		while (*alst)
		{
			newlst = (**alst).next;
			(*del)((**alst).content, (**alst).content_size);
			free(*alst);
			*alst = newlst;
		}
	}
}
