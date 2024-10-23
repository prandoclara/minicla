/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:39:08 by claprand          #+#    #+#             */
/*   Updated: 2024/04/04 16:31:25 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_putnbr_fd writes the given integer n on the given
	file descriptor by converting it into char.

	RETURN VALUE :
	None.
*/

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd (n / 10, fd);
	}
	ft_putchar_fd (n % 10 + '0', fd);
}

/*
int main(void)
{
	ft_putnbr_fd(-2147483648, 1);
}
*/