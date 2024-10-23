/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:35:59 by claprand          #+#    #+#             */
/*   Updated: 2024/04/22 15:16:14 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printux(unsigned int x, char c, int *len)
{
	if (x >= 16)
	{
		ft_printux(x / 16, c, len);
		ft_printux(x % 16, c, len);
	}
	else
	{
		if (x <= 9)
		{
			ft_putchar_fd(x + 48, 1);
			*len += ft_hex_len(x);
		}
		else
		{
			ft_putchar_fd(ft_toupper(x - 10 + 97), 1);
			*len += ft_hex_len(x);
		}
	}
	return (*len);
}
