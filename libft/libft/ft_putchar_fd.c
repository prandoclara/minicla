/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:34:10 by claprand          #+#    #+#             */
/*   Updated: 2024/04/04 15:03:30 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_putchar_fd writes the given character to the given
	file descriptor.

	RETURN VALUE :
	None.
*/

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

/*int	main(void)
{
	char	c;

	c = 'a';
	ft_putchar_fd(c, 1);
	return (0);
}*/
