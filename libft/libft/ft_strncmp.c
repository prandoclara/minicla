/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:45:57 by claprand          #+#    #+#             */
/*   Updated: 2024/04/04 15:06:22 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_strncmp compares the first n bytes of the given strings
	s1 and s2.

	RETURN VALUE :
	An integer less than, equal to, or greater than zero if one of the first
	n bytes of s1 is found to be less than, to match, or to be greater than 
	s2.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && (i < n - 1))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <stdio.h>
int main(void)
{
	char s1[] = "hello";
	char s2[] = "hello";
	char s3[] = "bonjour";
	char s4[] = "";

	printf("%d\n", ft_strncmp(s1, s2, 5));
	printf("%d\n", ft_strncmp(s1, s3, 5));
	printf("%d\n", ft_strncmp(s1, s4, 5));
	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
	printf("\n");
	printf("%d\n", strncmp(s1, s2, 5));
	printf("%d\n", strncmp(s1, s3, 5));
	printf("%d\n", strncmp(s1, s4, 5));
	printf("%d\n", strncmp("test\200", "test\0", 6));
	return (0);
}
*/