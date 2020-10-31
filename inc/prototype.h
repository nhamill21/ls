/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:40:59 by nhamill           #+#    #+#             */
/*   Updated: 2020/10/31 12:40:59 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_PROTOTYPE_H
# define LS_PROTOTYPE_H

# include "struct.h"

int		ft_exit(int status, t_ls *ls);
t_ls	*init_ls(int ac, char **av, t_ls *ls);

t_list	*ft_lstnew(void *data);
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstdelone(t_list **del);

t_heap	*get_stack(t_stack *stack);
t_stack	*new_stack(t_heap *data);
void 	push_stack(t_stack **stack, t_stack *new);
void 	pop_stack(t_stack **stack);

char	*get_heap_min(t_heap *heap);
char	*get_heap_max(t_heap *heap);
void	heap_sort(t_heap *heap, int (*f)(const char *, const char *));
int		add_heap_elem(t_heap **heap, char *data,
					int (*f)(const char *, const char *));

#endif
