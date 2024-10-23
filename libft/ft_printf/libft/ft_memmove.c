/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:29:31 by claprand          #+#    #+#             */
/*   Updated: 2024/04/08 14:27:13 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_memmove copies n bytes from memory area src to memory
	area dst. The memory areas may overlap: if the dst pointer is found
	to be between the src pointer and the index n, copying will be done
	back to front to prevent data being modified before being copied.
	Otherwise it will be done front to back	to preserve data.

	RETURN VALUE :
	A pointer to dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}

/*
#include <stdio.h>
int main()
{
	char s[20] = "hello";
	char x[] = "bonjour";
	char src[] = "lorem ipsum dolor sit amet";
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	// char sResult2[] = {67, 67, 68, 68, 69, 0, 45};
	char *dest;
	size_t	len;

	dest = src + 1;
	len = 7;
	printf("%s\n", (char *)ft_memmove(x, s, len));
	printf("%s\n", (char *)ft_memmove(src, dest, 8));
	printf("%s\n", (char *)ft_memmove(src, dest, 0));
	printf("%s\n", (char *)ft_memmove(dest, src, 8));
	printf("%s\n", (char *)ft_memmove(sResult + 1, sResult, 2));
	printf("\n");
	printf("%s\n", (char *)memmove(s, x, len));
	printf("%s\n", (char *)memmove(src, dest, 8));
	printf("%s\n", (char *)memmove(src, dest, 0));
	printf("%s\n", (char *)memmove(dest, src, 8));
	printf("%s\n", (char *)memmove(sResult + 1, sResult, 2));
	return (0);
}
*/