/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:45:53 by nhamill           #+#    #+#             */
/*   Updated: 2020/10/31 16:45:53 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*ft_lstnew(void *data)
{
	t_list		*new;

	new = NULL;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void 	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (new)
	{
		if (alst && *alst)
		{
			tmp = new;
			while (tmp->next)
				tmp = (t_list *) tmp->next;
			tmp->next = (t_list *) *alst;
		}
		*alst = new;
	}

}

void 	ft_lstdelone(t_list **del)
{
	t_list	*tmp;

	if (del)
	{
		tmp = *del;
		*del = (t_list *) (*del)->next;
		free(tmp);
		tmp = NULL;
	}
}
