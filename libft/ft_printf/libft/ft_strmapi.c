/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:47:33 by claprand          #+#    #+#             */
/*   Updated: 2024/04/08 15:36:43 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESRIPTION :
	The function ft_strmapi applies the given function f to each character
	in the given string s and allocates sufficient memory to store the
	resulting new string. 

	RETURN VALUE :
	A pointer to the newly created string. NULL if the memory allocation
	fails.	
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	while (str[i])
	{
		str[i] = (*f)(i, str[i]);
		i++;
	}
	return (str);
}

/*
char	mapi(unsigned int i, char c)
{
	static int	indexArray[11] = {0};

	if (i > 10 || indexArray[i] == 1)
		write(1, "wrong index\n", 12);
	else
		indexArray[i] = 1;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}


#include <stdio.h>
int		main(void)
{
	char	*str;
	char	*strmapi;

	str = (char *)malloc(sizeof(*str) * 12);

	strcpy(str, "LoReM iPsUm");
	strmapi = ft_strmapi(str, &mapi);
	printf("%s\n", strmapi);
	return (0);
}
*/