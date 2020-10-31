/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:47:07 by nhamill           #+#    #+#             */
/*   Updated: 2020/10/31 13:47:07 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void set_flags(const char *str, unsigned *flags)
{
	int 		i;
	unsigned 	flag;
	char		*s;

	i = 1;
	while (*(str + i) && !(*flags & FAIL))
	{
		flag = ((s = strchr(FLAGS, *(str + i))) ? 1 << (s - FLAGS) : FAIL);
		if (flag & SORT)
			*flags = (*flags & NULL_SORT) | flag;
		else if (flag & LONG_LIST)
			*flags = (*flags & NULL_FRMT_OUT) | flag | LWR_L;
		else if (flag & FRMT_OUT)
			*flags = (*flags & NULL_FRMT_OUT) | flag;
		else if (flag & TIME)
			*flags = (*flags & NULL_TIME) | flag;
		else if (flag & LWR_F)
			*flags |= LWR_F | LWR_A;
		else
			*flags |= flag;
		i++;
	}
}

static int	search_flags(int ac, char **av, unsigned *flags)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (*(av + i) && *(*(av + i)) == '-' && *(*(av + i) + 1))
		{
			if (*(*(av + i) + 1) == '-')
			{
				*flags = (*(*(av + i) + 2) ? *flags | FAIL : *flags);
				*(av + i) = NULL;
				return (ac - i - 1);
			}
			set_flags(*(av + i), flags);
			*(av + i) = NULL;
		}
		else
			break ;
		i++;
	}
	return (ac - i);
}

static int	add_files_dirs(char *name, t_heap **dirs, t_heap **files, t_ls *ls)
{
	DIR		*dr;

	errno = 0;
	if ((dr = opendir(name)))
	{
		closedir(dr);
		if (add_heap_elem((ls->flags & LWR_D ? files : dirs),
					strdup(name), ls->func))
			return (1);
	}
	else if (errno == ENOTDIR)
	{
		if (add_heap_elem(files, strdup(name), ls->func))
			return (1);
	}
	else
	{
		perror(name);
		ls->exit = SERIOUS_TROUBLE;
	}
	return (0);
}

static void set_first_args(int ac, char **av, t_ls *ls)
{
	int		i;
	t_heap	*dirs;
	t_heap	*files;

	i = 1;
	dirs = NULL;
	files = NULL;
	while (i < ac)
	{
		if (*(av + i))
			if (add_files_dirs(*(av + i), &dirs, &files, ls))
			{
//				free_heap(dirs);
//				free_heap(files);
				ft_exit(4, ls);
			}
		i++;
	}
	if (!dirs && !files)
		if (add_heap_elem(&dirs, strdup("."), ls->func))
			ft_exit(4, ls);
	push_stack(&ls->stack, new_stack(dirs));
	push_stack(&ls->stack, new_stack(files));
}

t_ls		*init_ls(int ac, char **av, t_ls *ls)
{
	ls->count = search_flags(ac, av, &ls->flags);
	if (ls->flags & FAIL)
		ft_exit(1, ls);
	if (ls->flags & LWR_F)
		ls->func = strcmp;
	else if (ls->flags & LWR_T)
		ls->func = NULL;
	else if (ls->flags & UPR_S)
		ls->func = NULL;
	set_first_args(ac, av, ls);
	return (ls);
}
