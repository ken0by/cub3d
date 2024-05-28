/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:19:41 by rofuente          #+#    #+#             */
/*   Updated: 2023/03/28 13:11:46 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux;

	aux = lst;
	while (aux != NULL)
	{
		if (aux->next == NULL)
			break ;
		aux = aux->next;
	}
	return (aux);
}
