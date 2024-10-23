/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:10:07 by claprand          #+#    #+#             */
/*   Updated: 2024/04/05 08:56:05 by claprand         ###   ########.fr       */
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
	size_t	s2len;
	size_t	i;
	size_t	j;

	s2len = ft_strlen((char *)s2);
	if (s1 == s2 || s2len == 0)
		return ((char *)s1);
	i = 0;
	if (s1[i] == '\0')
		return (0);
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < len && s1[i] && s2[i])
		{
			j++;
			if ((j == len && j == s2len) || j == s2len)
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	char s1[] = "hello bonjour comment ca va?";
	char s2[] = "jour";
	char s3[] = "";
	char s4[] = "4";

	printf("%s\n", ft_strnstr(s1, s2, 20));
	printf("%s\n", ft_strnstr(s1, s3, 20));
	printf("%s\n", ft_strnstr(s1, s4, 20));
	printf("%s\n", ft_strnstr(s3, s2, 20));
	printf("%s\n", ft_strnstr(s1, s2, 10));
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));
	printf("\n");
	printf("%s\n", strnstr(s1, s2, 20));
	printf("%s\n", strnstr(s1, s3, 20));
	printf("%s\n", strnstr(s1, s4, 20));
	printf("%s\n", strnstr(s3, s2, 20));
	printf("%s\n", strnstr(s1, s2, 10));
	printf("%s\n", strnstr("lorem ipsum dolor sit amet", "dolor", 15));
	printf("%s\n", strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));
	printf("\n");
	printf("\n");
	printf("NEW");
	printf("\n");
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 15));
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dol", 30));
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "sit", 10));
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
	printf("\n");
	printf("NEW");
	printf("\n");
	printf("%s\n", strnstr("lorem ipsum dolor sit amet", "ipsum", 15));
	printf("%s\n", strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));
	printf("%s\n", strnstr("lorem ipsum dolor sit amet", "dol", 30));
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "sit", 10));
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
	return (0);
}
*/