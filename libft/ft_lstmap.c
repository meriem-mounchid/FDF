/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 22:17:09 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/27 00:45:16 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*newlst;
	t_list		*head;

	head = NULL;
	if (lst)
	{
		newlst = (*f)(lst);
		head = newlst;
		while ((*lst).next != NULL)
		{
			(*newlst).next = (*f)((*lst).next);
			newlst = (*newlst).next;
			lst = (*lst).next;
		}
	}
	return (head);
}
