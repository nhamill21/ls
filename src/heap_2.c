/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:03:59 by nhamill           #+#    #+#             */
/*   Updated: 2020/10/31 16:03:59 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_item		*get_heap_max(t_heap *heap)
{
	if (heap->first == heap->last)
		return (NULL);
	heap->first++;
	return (heap->item + heap->first - 1);
}

t_item 		*get_heap_min(t_heap *heap)
{
	if (heap->last == heap->first)
		return (NULL);
	heap->last--;
	return (heap->item + heap->last);
}
