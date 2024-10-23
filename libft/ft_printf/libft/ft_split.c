/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:17:26 by claprand          #+#    #+#             */
/*   Updated: 2024/05/21 10:23:56 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_split allocates and copies an array of strings by 
	splitting the given string s using the given separator c.

	RETURN VALUE :
	An array of strings resulting from the split. NULL if the memory
	allocation fails.
*/

static int	count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			words++;
		if (i > 0 && s[i] != c && s[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

static char	**malloc_strs(char **strs, const char *s, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		if ((s[i] == c && i > 0 && s[i - 1] != c)
			|| (s[i] != c && s[i + 1] == '\0'))
		{
			strs[j] = malloc((count + 1) * sizeof(char));
			if (!strs[j])
				return (NULL);
			count = 0;
			j++;
		}
		i++;
	}
	return (strs);
}

static char	**write_strs(char **strs, const char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
			strs[j][k++] = s[i];
		if (s[i] != c && s[i + 1] == '\0')
			strs[j][k] = '\0';
		if (s[i] == c && i > 0 && s[i - 1] != c)
		{
			strs[j][k] = '\0';
			j++;
			k = 0;
		}
		i++;
	}
	return (strs);
}

static char	**free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		wordcount;

	if (!s)
	{
		strs = malloc(1 * sizeof(char));
		if (!strs)
			return (NULL);
		*strs = NULL;
		return (strs);
	}
	wordcount = count_words(s, c);
	strs = malloc((wordcount + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	if (malloc_strs(strs, s, c))
	{
		write_strs(strs, s, c);
		strs[wordcount] = NULL;
	}
	else
		strs = free_strs(strs);
	return (strs);
}

/*
#include <stdio.h>
int main(void)
{
	char s[] = "hello comment ca va";
	char c = ' ';
	char **result = ft_split(s, c);
	int i;

	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	free_strs(result);
	return (0);
}*/