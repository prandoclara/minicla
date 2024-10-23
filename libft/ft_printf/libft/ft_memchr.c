/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:30:41 by claprand          #+#    #+#             */
/*   Updated: 2024/04/04 15:29:54 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_memchr searches n bytes of the memory area pointed to
	by s for the first occurence of c. Both c and the bytes of s are
	interpreted as unsigned char.

	RETURN VALUE:
	A pointer to the matching byte. NULL if the character does not occur
	in the given memory area.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	char s[] = "hello";
	char x[] = "bonjour";
	char z[] = "";
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};



	int c;
	c = 'l';

	printf("%s\n", (char *)ft_memchr(s, c, 10));
	printf("%s\n", (char *)ft_memchr(x, c, 10));
	printf("%s\n", (char *)ft_memchr(z, c, 10));
	printf("%s\n", (char *)ft_memchr(tab, -1, 7));
	printf("\n");
	printf("%s\n", (char *)memchr(s, c, 10));
	printf("%s\n", (char *)memchr(x, c, 10));
	printf("%s\n", (char *)memchr(z, c, 10));
	printf("%s\n", (char *)memchr(tab, -1, 7));
	return (0);
}
*/