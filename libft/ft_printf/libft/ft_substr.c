/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:20:00 by claprand          #+#    #+#             */
/*   Updated: 2024/04/09 12:03:39 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_substr extracts a substring from the given string by
	allocating sufficient memory for the new string starting at index start
	and ending at len characters.

	RETURN VALUE :
	A pointer to the new string.
	NULL if the memory allocation fails.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	reslen;

	if (!s)
		return (0);
	if ((size_t)ft_strlen((char *)s) < (size_t)start)
		return (ft_strdup(""));
	s = s + start;
	if ((size_t)ft_strlen((char *)s) < len)
		reslen = ft_strlen((char *)s) + 1;
	else
		reslen = len + 1;
	new_str = malloc(reslen * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy((char *)new_str, (char *)s, reslen);
	return (new_str);
}

/*
#include <stdio.h>
int main(void)
{
	char s[] = "hello";
	char	str[] = "lorem ipsum dolor sit amet";

	printf("%s\n", ft_substr(s, 4, 20));
	printf("%s\n", ft_substr(str, 0, 10));
	printf("%s\n", ft_substr(str, 7, 10));
	printf("%s\n", ft_substr(str, 7, 10));
	printf("%s\n", ft_substr(str, 0, 10));
	return (0);
}
*/