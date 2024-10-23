/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:41:49 by claprand          #+#    #+#             */
/*   Updated: 2024/04/04 14:56:38 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_bzero erases data in the n bytes of memory starting
	at location s by writing '\0's.

	RETURN VALUE :
	None.
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include <stdio.h>
int main(void)
{
	char s[] = "hello";
	char x[] = "hello";
	size_t n; 

	n = 1;
	ft_bzero((char *)s, n);
	bzero((char *)x, n);
	
	printf("%s\n", s);
	printf("%s\n", x);
	return (0);
}
*/
