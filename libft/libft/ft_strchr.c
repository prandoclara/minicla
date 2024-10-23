/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:49:09 by claprand          #+#    #+#             */
/*   Updated: 2024/04/04 16:32:11 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_strchr finds the first occurence of character c in
	string str.

	RETURN VALUE :
	A pointer to the first occurence of c in str.
	NULL if c is not found.
*/

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = c;
	if (ch == '\0')
	{
		i = ft_strlen((char *)s);
		return ((char *)s + i++);
	}
	while ((char)s[i])
	{
		if ((char)s[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	char s[] = "hello";
	int c;

	c = 'l';
	printf("%s\n", ft_strchr(s, c));
	printf("%s\n", ft_strchr(s, 's'));
	printf("%s\n", ft_strchr(s, '\0'));
	printf("\n");
	printf("%s\n", strchr(s, c));
	printf("%s\n", strchr(s, 's'));
	printf("%s\n", strchr(s, '\0'));
	return (0);
}
*/