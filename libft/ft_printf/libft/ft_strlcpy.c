/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:52:22 by claprand          #+#    #+#             */
/*   Updated: 2024/04/08 13:54:13 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_strlcpy copies up to size - 1 characters from the given
	string src to the given string dst, nul-terminating the result.

	Note : space for the terminating \0 character must be included in dstsize.

	RETURN VALUE :
	The total length of the string that it tried to create : the length of
	src, with the goal to facilitate truncaction detection.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/*
#include <stdio.h>
int main(void)
{
	char s1[] = "hello";
	char s2[] = "world !";
	char s3[] = "";
	char *dest;
	char src[] = "coucou";
	char dst[10]; 
	memset(dst, 'A', 10);
	
	dest = (char *)malloc(sizeof(*dest) * 15);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	
	printf("%lu\n", ft_strlcpy(s1, s2, 6));
	printf("%lu\n", ft_strlcpy(s1, s3, 6));
	printf("%lu\n", ft_strlcpy(s3, s2, 1));
	printf("%lu\n", ft_strlcpy(s1, s2, 2));
	printf("%lu\n", ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0));
	write(1, dest, 16);
	write(1, "\n", 1);
	printf("%lu\n", ft_strlcpy(dst, src, 0));
	printf("\n");
	printf("%lu\n", strlcpy(s1, s2, 6));
	printf("%lu\n", strlcpy(s1, s3, 6));
	printf("%lu\n", strlcpy(s3, s2, 1));
	printf("%lu\n", strlcpy(s1, s2, 2));
	printf("%lu\n", ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0));
	write(1, dest, 16);
	write(1, "\n", 1);
	printf("%lu\n", strlcpy(dst, src, 0));
	return (0);
}
*/