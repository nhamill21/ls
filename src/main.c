/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:32:43 by nhamill           #+#    #+#             */
/*   Updated: 2020/10/31 12:32:43 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_ls	*get_fresh_ls(void)
{
	t_ls	*ls;

	ls = NULL;
	if (!(ls = (t_ls *)malloc(sizeof(t_ls))))
		return (NULL);
	if (!(ls->stack = (t_stack *)malloc(sizeof(t_stack))))
	{
		free(ls);
		return (NULL);
	}
	ls->exit = 0;
	ls->stack = NULL;
	ls->flags = DEFAULT;
	return (ls);
}

static void type_of_ls(t_ls *ls)
{
	t_heap		*dirs;
	t_heap		*files;

	files = get_stack(ls->stack);
	dirs = get_stack(ls->stack->next);
	if (files)
		work_with_files(files, ls);
	else if (dirs && dirs->last == 1)
		work_with_one_dir(dirs, ls);
	pop_stack(&ls->stack);
	dirs = get_stack(ls->stack);
	if (dirs)
		(ls->flags & UPR_R ? recurs(ls) : non_recurs(ls));
}

int		main(int ac, char **av)
{
	t_ls	*ls;
	int		status;

	status = 0;
	if ((ls = get_fresh_ls()) != NULL)
	{
		ls = init_ls(ac, av, ls);
		print(ls);
		type_of_ls(ls);
		status = ls->exit;
//		free_all(ls);
	}
	else
		status = SERIOUS_TROUBLE;
	return (status);
}
