/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:39:43 by claprand          #+#    #+#             */
/*   Updated: 2024/04/04 15:28:11 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_memset fills the first len bytes of the memory area
	pointed	to by b with the byte c. Both b and c are interpreted as 
	unsigned char.

	RETURN VALUE :
	A pointer to memory area s.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (char)c;
		i++;
	}
	return (b);
}

/*
#include <stdio.h>
int main(void)
{
	char s[] = "hello";
	int c;

	c = 'a';
	printf("%s\n", (char *)ft_memset(s, c, 2));
	printf("%s\n", (char *)memset(s, c, 2));
	return (0);
}
*/