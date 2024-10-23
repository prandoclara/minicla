/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:06:39 by claprand          #+#    #+#             */
/*   Updated: 2024/04/06 12:46:16 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_memcmp compares the first n bytes of the memory areas
	s1 and s2. The bytes are interpreted as unsigned char.

	RETURN VALUE :
	An integer less than, equal to, or greater than zero if the first
	n bytes of s1 is found to be less than, equal to, or greater than the 
	first n bytes of s2. Zero if n is equal to zero.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*str1;
	const char	*str2;
	size_t		i;

	if (n == 0)
		return (0);
	str1 = (const char *)s1;
	str2 = (const char *)s2;
	i = 0;
	while ((i < n - 1) && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

/*
#include <stdio.h>
int main(void)
{
	char s[] = "hello";
	char x[] = "bonjour";
	char z[] = "hello";
	char a[] = "\0";
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};

	printf("%d\n", ft_memcmp(s, x, 10));
	printf("%d\n", ft_memcmp(s, z, 10));
	printf("%d\n", ft_memcmp(a, x, 10));
	printf("%d\n", ft_memcmp("t\200", "t\0", 2));
	printf("%d\n", ft_memcmp("testss", "test", 5));
	printf("%d\n", ft_memcmp("test", "tEst", 4));
	printf("%d\n", ft_memcmp("abcdefgh", "abcdwxyz", 6));
	printf("%d\n", ft_memcmp(s2, s3, 4));
	printf("\n");
	printf("%d\n", memcmp(s, x, 10));
	printf("%d\n", memcmp(s, z, 11));
	printf("%d\n", memcmp(a, x, 10));
	printf("%d\n", memcmp("t\200", "t\0", 2));
	printf("%d\n", memcmp("testss", "test", 5));
	printf("%d\n", memcmp("test", "tEst", 4));
	printf("%d\n", memcmp("abcdefgh", "abcdwxyz", 6));
	printf("%d\n", memcmp(s2, s3, 4));
	return (0);
}
*/