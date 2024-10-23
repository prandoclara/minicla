/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:05:21 by claprand          #+#    #+#             */
/*   Updated: 2024/04/04 14:57:57 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	The function ft_isprint checks whether c is a printable character or not.

	RETURN VALUE :
	Non-zero if c is printable, zero if not.
*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int a;
	int b;
	int c;
	int d;
	int f;

	a = '1';
	b = 'Z';
	c = ' ';
	d = '$';
	f = 128;
	printf("%d\n", ft_isprint(a));
	printf("%d\n", ft_isprint(b));
	printf("%d\n", ft_isprint(c));
	printf("%d\n", ft_isprint(d));
	printf("%d\n", ft_isprint(f));
	printf("\n");
	printf("%d\n", isprint(a));
	printf("%d\n", isprint(b));
	printf("%d\n", isprint(c));
	printf("%d\n", isprint(d));
	printf("%d\n", isprint(f));
	return (0);
}
*/