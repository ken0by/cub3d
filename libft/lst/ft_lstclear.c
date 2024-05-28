/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:56:41 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:11:39 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!*lst || !del)
		return ;
	if (!lst)
		return ;
	while (*lst != NULL)
	{
		aux = lst[0]->next;
		ft_lstdelone(*lst, *del);
		lst[0] = aux;
	}
	*lst = NULL;
}
