/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:42:47 by nhamill           #+#    #+#             */
/*   Updated: 2020/10/31 12:42:47 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_STRUCT_H
# define LS_STRUCT_H

#include "ft_ls.h"
#include <dirent.h>

typedef struct		s_item {
	char			*arg;
	char			*out;
	DIR				*dir;
	struct stat		*stat;
	struct dirent	*dirent;
}					t_item;

typedef struct		s_heap {
	t_item			*item;
	int				first;
	int				last;
	int				size;
}					t_heap;

typedef struct		s_list {
	void			*data;
	struct s_list	*next;
}					t_list;

typedef struct		s_stack {
	t_heap			*data;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_ls {
	int				count;
	int				exit;
	unsigned		flags;
	int				(*func)(const char *s1, const char *s2, unsigned flags);
	t_stack			*stack;
}					t_ls;

typedef struct		s_pair {
	int 			left;
	int 			right;
}					t_pair;

#endif
