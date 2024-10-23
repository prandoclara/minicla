/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:39:28 by claprand          #+#    #+#             */
/*   Updated: 2024/04/04 16:34:23 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_strlcat appends the given string src to the end of 
	dst. It will append at most dstsize - ft_strlen(dst) - 1 and 
	nul-terminate the result.

	Note : space for the terminating \0 character must be included in dstsize.

	RETURN VALUE :
	The total length of the string that it tried to create : the initial
	length of dst + the length of src, with the goal to facilitate
	truncaction detection.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *) src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[i] && (dst_len + i) < (dstsize - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
#include <stdio.h>
int main(void)
{
	char s1[] = "hello";
	char s2[] = "world !";
	char s3[] = "";
	
	printf("%lu\n", ft_strlcat(s1, s2, 6));
	printf("%lu\n", ft_strlcat(s1, s3, 6));
	printf("%lu\n", ft_strlcat(s3, s2, 1));
	printf("%lu\n", ft_strlcat(s1, s2, 4));
	printf("\n");
	printf("%lu\n", strlcat(s1, s2, 6));
	printf("%lu\n", strlcat(s1, s3, 6));
	printf("%lu\n", strlcat(s3, s2, 1));
	printf("%lu\n", strlcat(s1, s2, 4));
	return (0);
}
*/