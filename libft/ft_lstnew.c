/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 03:03:19 by twakrim           #+#    #+#             */
/*   Updated: 2018/10/26 21:19:24 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*element;

	element = (t_list *)malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	if (content == NULL)
	{
		(*element).content = NULL;
		(*element).content_size = 0;
	}
	else
	{
		(*element).content = (void *)malloc(sizeof(content));
		(*element).content_size = content_size;
		ft_memcpy((*element).content, content, content_size);
	}
	(*element).next = NULL;
	return (element);
}
