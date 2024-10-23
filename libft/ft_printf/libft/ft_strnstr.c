/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:10:07 by claprand          #+#    #+#             */
/*   Updated: 2024/05/21 11:01:51 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_strnstr searches the first n bytes of the given string
	s1 for the first occurence of the full string s2.
	Characters that appear after \0 are not searched.

	RETURN VALUE :
	A pointer to the first character of the first occurrence of s2.
	A pointer to s1 if s2 is empty.
	NULL if s2 occurs nowhere in s1.
*/

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	if (s2[0] == 0)
		return ((char *)s1);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < len)
		{
			if (s1[i + j] == 0 && s2[j] == 0)
				return ((char *)&s1[i]);
			j++;
		}
		if (s2[j] == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (0);
}
