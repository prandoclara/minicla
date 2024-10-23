/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:39:20 by claprand          #+#    #+#             */
/*   Updated: 2024/04/04 15:03:41 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_putendl_fd writes the given string to the given
	file descriptor followed by a new line.

	RETURN VALUE :
	None.
*/

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
	ft_putchar_fd ('\n', fd);
}

/*int main(void)
{
	char s[] = "Bonjour";

	ft_putendl_fd(s, 1);
	return (0);
}*/