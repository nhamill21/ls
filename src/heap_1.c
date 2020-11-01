/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:03:59 by nhamill           #+#    #+#             */
/*   Updated: 2020/10/31 16:03:59 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	sift_down(t_heap *heap, unsigned fg, t_pair pair,
					  int (*func)(const char *, const char *, unsigned))
{
	char	*tmp;
	int		child;
	int		parent;

	parent = 0;
	child = (func((heap->item + pair.left)->arg, (heap->item + pair.right)->arg,
			   fg) > 0 ? pair.left : pair.right);
	while (func((heap->item + parent)->arg, (heap->item + child)->arg, fg) < 0)
	{
		tmp = (heap->item + parent)->arg;
		(heap->item + parent)->arg = (heap->item + child)->arg;
		(heap->item + child)->arg = tmp;
		parent = child;
		pair.left = (2 * parent + 1 < heap->last ? 2 * parent + 1 : parent);
		pair.right = (2 * parent + 2 < heap->last ? 2 * parent + 2 : parent);
		child = (func((heap->item + pair.left)->arg,
				(heap->item + pair.right)->arg, fg) > 0
						? pair.left : pair.right);
	}
}

static void	sift_up(t_heap *heap, unsigned flags,
					int (*func)(const char *, const char *, unsigned))
{
	char	*tmp;
	int		child;
	int		parent;

	if ((child = heap->last - 1) == heap->first)
		return ;
	while ((parent = (child % 2 ? child / 2 : child / 2 - 1)) >= 0 &&
	func((heap->item + parent)->arg, (heap->item + child)->arg, flags) < 0)
	{
		tmp = (heap->item + parent)->arg;
		(heap->item + parent)->arg = (heap->item + child)->arg;
		(heap->item + child)->arg = tmp;
		child = parent;
	}
}

void		heap_sort(t_heap *heap, unsigned flags,
				int (*func)(const char *, const char *, unsigned))
{
	char	*tmp;
	int		last;
	t_pair	pair;

	last = heap->last;
	while (heap->last > heap->first)
	{
		tmp = (heap->item + heap->last - 1)->arg;
		(heap->item + heap->last - 1)->arg = heap->item->arg;
		heap->item->arg = tmp;
		if (--heap->last == heap->first + 1)
			break ;
		pair.left = (2 * heap->first + 1 < heap->last ? 2 * heap->first + 1 :
				heap->first);
		pair.right = (2 * heap->first + 2 < heap->last ? 2 * heap->first + 2
				: heap->first);
		sift_down(heap, flags, pair, func);
	}
	heap->last = last;
}

static void	realloc_heap(t_heap **heap, char *data)
{
	if ((*heap)->last == (*heap)->size)
	{
		(*heap)->size *= COEF_HEAP_INC;
		(*heap)->item = realloc((*heap)->item, (*heap)->size * sizeof(t_item));
	}
	((*heap)->item + (*heap)->last)->arg = data;
	(*heap)->last++;
}

int 		add_heap_elem(t_heap **heap, char *data, unsigned flags,
					int (*func)(const char *, const char *, unsigned))
{
	if (heap && data)
	{
		if (!*heap)
		{
			if (!(*heap = (t_heap *)malloc(sizeof(t_heap))))
				return (1);
			(*heap)->first = 0;
			(*heap)->last = 1;
			(*heap)->size = START_HEAP_SIZE;
			if (!((*heap)->item = (t_item *)malloc(sizeof(t_item))))
			{
				free(*heap);
				return (1);
			}
			(*heap)->item->arg = data;
			(*heap)->item->out = NULL;
			(*heap)->item->dir = NULL;
			(*heap)->item->dirent = NULL;
			(*heap)->item->stat = NULL;
		}
		else
			realloc_heap(heap, data);
		sift_up(*heap, flags, func);
	}
	return (0);
}
