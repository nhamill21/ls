/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:06:01 by nhamill           #+#    #+#             */
/*   Updated: 2020/11/01 16:06:01 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	print_out(t_heap *heap)
{
	int 	i;

	if (!heap)
		return ;
	i = 0;
	while (i < heap->last)
	{
		printf("%s", (heap->item + i)->out);
		i++;
	}
}