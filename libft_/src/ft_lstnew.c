/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:30:55 by fsarkoh           #+#    #+#             */
/*   Updated: 2022/10/20 15:56:17 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newl;

	newl = (t_list *)malloc(sizeof(t_list));
	if (!newl)
		return (NULL);
	newl->content = content;
	newl->next = NULL;
	return (newl);
}
