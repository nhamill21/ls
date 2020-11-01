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

t_ls	*init_ls(int ac, char **av, t_ls *ls);

void	work_with_files(t_heap *files, t_ls *ls);
void	work_with_one_dir(t_heap *files, t_ls *ls);
void	recurs(t_ls *ls);
void	non_recurs(t_ls *ls);

int		ft_exit(int status, t_ls *ls);
void 	free_heap(t_heap *heap);

int 	file_out(t_item *item, int last, unsigned flags);
void 	print_out(t_heap *heap);

int 	lexicographic_sort(const char *s1, const char *s2, unsigned flags);
int 	size_sort(const char *s1, const char *s2, unsigned flags);
int 	time_sort(const char *s1, const char *s2, unsigned flags);

t_list	*ft_lstnew(void *data);
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstdelone(t_list **del);

t_heap	*get_stack(t_stack *stack);
t_stack	*new_stack(t_heap *data);
void 	push_stack(t_stack **stack, t_stack *new);
void 	pop_stack(t_stack **stack);

t_item 	*get_heap_min(t_heap *heap);
t_item 	*get_heap_max(t_heap *heap);
void	heap_sort(t_heap *heap, unsigned flags,
			   int (*f)(const char *, const char *, unsigned));
int		add_heap_elem(t_heap **heap, char *data, unsigned flags,
					int (*f)(const char *, const char *, unsigned));

#endif
