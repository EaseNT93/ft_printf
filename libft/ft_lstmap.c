/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:24:39 by dpants            #+#    #+#             */
/*   Updated: 2021/05/05 18:24:39 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*list_el;

	list_el = NULL;
	while (lst)
	{
		list = ft_lstnew(f(lst->content));
		if (!list)
		{
			ft_lstclear(&list_el, del);
			return (NULL);
		}
		ft_lstadd_back(&list_el, list);
		lst = lst->next;
	}
	return (list_el);
}
