/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 09:36:07 by nhamill           #+#    #+#             */
/*   Updated: 2020/11/01 09:36:07 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	init_items(t_heap *heap)
{
	int 			i;

	i = 0;
	while (i < heap->last)
	{
		stat((heap->item + i)->arg, (heap->item + i)->stat);
		i++;
	}
}

void	work_with_files(t_heap *files, t_ls *ls)
{
	if (!files)
		return ;
	init_items(files);
	heap_sort(files, ls->flags, ls->func);
//	if (file_out(files->item, files->last, ls->flags))
//		ft_exit(7, ls);
	print_out(files);
}

void	work_with_one_dir(t_heap *dir, t_ls *ls)
{
	printf("work with one dir\n");
	if (dir && ls && !(ls->flags & UPR_R))
	{
//		t_stack		*tmp = ls->stack->next;
		pop_stack(&ls->stack->next);
//		tmp = NULL;
	}
}

void	recurs(t_ls *ls)
{
	if (ls) NULL;
	printf("work with recurs\n");
}

void	non_recurs(t_ls *ls)
{
	if (ls) NULL;
	printf("work with dirs\n");
}
