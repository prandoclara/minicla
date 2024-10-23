/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:08:10 by claprand          #+#    #+#             */
/*   Updated: 2024/04/08 15:35:57 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_strrchr finds the last occurrence of character c in
	string str.

	RETURN VALUE :
	A pointer to the last occurrence of c in str.
	NULL if c is not found.
*/

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	s = NULL;
	return (NULL);
}

/*
#include <stdio.h>
int main(void)
{
	char s[] = "hello";
	char x[] = "";
	char *empty;
	char	str3[] = "bonjourno";
	char s3[] = "";
	int c;

	c = 'l';
	empty = (char *)malloc(1 * 1);
	printf("%s\n", ft_strrchr(s, c));
	printf("%s\n", ft_strrchr(empty, 'V'));
	printf("%s\n", ft_strrchr(x, 'V'));
	printf("%s\n", ft_strrchr(str3, '\0'));
	printf("%s\n", strrchr(s3, 0));
	printf("\n");
	printf("%s\n", strrchr(s, c));
	printf("%s\n", strrchr(empty, 'V'));
	printf("%s\n", strrchr(x, 'V'));
	printf("%s\n", strrchr(str3, '\0'));
	printf("%s\n", strrchr(s3, 0));
	return (0);
}
*/