/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:05:31 by nhamill           #+#    #+#             */
/*   Updated: 2020/11/01 17:05:31 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//static int get_count_out(unsigned flags)
//{
//	int		count;
//
//	count = 0;
//	if (flags & LWR_I)
//		count++;
//	if (flags & LWR_S)
//		count++;
//	if (flags & LWR_L)
//		count += ((flags & LWR_G) || (flags & LWR_O) ? 5 : 6);
//	if ((flags & LWR_P) || (flags & UPR_F))
//		count++;
//	return (count);
//}
//
//int 		inode_and_blocksize(t_item *item, int last, char **out,
//						  unsigned flags)
//{
//
//	return (0);
//}
//
//int 		file_out(t_item *item, int last, unsigned flags)
//{
//	int 	i;
//	int		count;
//	char 	**out;
//
//	i = 0;
//	count = get_count_out(flags);
//	if (!(out = (char **)malloc(sizeof(char *) * last)))
//		return (1);
//	if ((flags & LWR_I) || (flags & LWR_S))
//		if (inode_and_blocksize(item, last, out, flags))
//		{
//			free(out);
//			return (1);
//		}
//	return (0);
//}