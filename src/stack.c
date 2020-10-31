/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:45:53 by nhamill           #+#    #+#             */
/*   Updated: 2020/10/31 16:45:53 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_heap	*get_stack(t_stack *stack)
{
	return (stack ? stack->data : NULL);
}

t_stack	*new_stack(t_heap *data)
{
	return ((t_stack *)ft_lstnew((void *)data));
}

void 	push_stack(t_stack **stack, t_stack *new)
{
	ft_lstadd((t_list **)stack, (t_list *)new);
}

void 	pop_stack(t_stack **stack)
{
	ft_lstdelone((t_list **)stack);
}