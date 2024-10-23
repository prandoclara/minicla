/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:01:33 by claprand          #+#    #+#             */
/*   Updated: 2024/04/04 15:29:10 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_memcpy copies n bytes from memory area src to memory
	area dst.
	Does not account for memory overlaps. Use ft_memmove if the memory areas
	overlap or might overlap.

	RETURN VALUE :
	A pointer to dst. NULL if src and dst are both NULL.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}

/*
#include <stdio.h>
int main(void)
{
	char s[] = "hello";
	char x[] = "bonjour";
	size_t n; 

	n = 5;
	printf("%s\n", (char *)ft_memcpy(s, x, n));
	printf("\n");
	printf("%s\n", (char *)memcpy(s, x, n));
	return (0);
}
*/