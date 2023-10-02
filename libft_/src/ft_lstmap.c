/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:06:04 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/07/12 14:28:23 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*temp;

	if (!f || !del)
		return (NULL);
	n_lst = NULL;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
		{
			while (n_lst)
			{
				temp = n_lst->next;
				(*del)(n_lst-> content);
				free(n_lst);
				n_lst = temp;
			}
			return (NULL);
		}
		ft_lstadd_back(&n_lst, temp);
		lst = lst->next;
	}
	return (n_lst);
}
