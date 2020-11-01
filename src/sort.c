/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:22:35 by nhamill           #+#    #+#             */
/*   Updated: 2020/11/01 13:22:35 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 	lexicographic_sort(const char *s1, const char *s2, unsigned flags)
{
	int 		i;
	const char 	*str1;
	const char 	*str2;

	printf("%s - %s\n", s1, s2);
	if (!s1 || !s2)
		return 0;
	str1 = strrchr(s1, SEP_PATH);
	str2 = strrchr(s2, SEP_PATH);
	str1 = (!str1 ? s1 : str1 + 1);
	str2 = (!str2 ? s2 : str2 + 1);
	i = 0;
	while (*(str1 + i) == *(str2 + i) && *(str1 + i))
		i++;
	if (flags & LWR_R) {
		return ((unsigned char) *(str2 + i) - (unsigned char) *(str1 + i));
	} else {
		return ((unsigned char) *(str1 + i) - (unsigned char) *(str2 + i));
	}
}

int 	size_sort(const char *s1, const char *s2, unsigned flags)
{
	struct stat		s_stat1;
	struct stat		s_stat2;
	long long		size1;
	long long		size2;

	if (!s1 || !s2)
		return 0;
	stat(s1, &s_stat1);
	stat(s2, &s_stat2);
	size1 = s_stat1.st_size;
	size2 = s_stat2.st_size;
	if (size1 == size2)
		return (0);
	if (flags & LWR_R) {
		return (size2 - size1 > 0 ? 1 : -1);
	} else {
		return (size1 - size2 > 0 ? 1 : -1);
	}
}

int 	time_sort(const char *s1, const char *s2, unsigned flags)
{
	long 			diff;
	long			time1;
	long			time2;
	struct stat		s_stat1;
	struct stat		s_stat2;

	if (!s1 || !s2)
		return 0;
	stat(s1, &s_stat1);
	stat(s2, &s_stat2);
	if (flags & LWR_C)
	{
		time1 = s_stat1.st_mtimespec.tv_sec;
		time2 = s_stat2.st_mtimespec.tv_sec;
	}
	else
	{
		time1 = (flags & LWR_U ? s_stat1.st_atimespec.tv_sec : s_stat1
				.st_birthtimespec.tv_sec);
		time2 = (flags & LWR_U ? s_stat2.st_atimespec.tv_sec : s_stat2
				.st_birthtimespec.tv_sec);
	}
	diff = (flags & LWR_R ? time2 - time1 : time1 - time2);
	return (diff > 0 ? 1 : -1);
}