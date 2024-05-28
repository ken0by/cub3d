/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:56:19 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:11:48 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	*ft_free(void *s, t_list *nl, void (*del)(void *))
{
	del(s);
	ft_lstclear(&nl, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*nl;
	t_list	*aux2;
	void	*s;

	if (!lst || !f || !del)
		return (0);
	aux = NULL;
	nl = aux;
	aux2 = lst;
	while (aux2)
	{
		s = f(aux2->content);
		if (!s)
			return (ft_free(s, nl, del));
		aux = ft_lstnew(s);
		if (!aux)
			return (ft_free(s, nl, del));
		aux2 = aux2->next;
		ft_lstadd_back(&nl, aux);
	}
	return (nl);
}
