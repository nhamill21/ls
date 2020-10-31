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

char 		*get_heap_max(t_heap *heap)
{
	if (heap->first == heap->last)
		return (NULL);
	heap->first++;
	return (*(heap->arr + heap->first - 1));
}

char 		*get_heap_min(t_heap *heap)
{
	if (heap->last == heap->first)
		return (NULL);
	heap->last--;
	return (*(heap->arr + heap->last));
}
