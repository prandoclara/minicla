/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:46:17 by claprand          #+#    #+#             */
/*   Updated: 2024/04/20 15:00:26 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int n)
{
	if (n == 0 || (n > 0 && n <= 9))
	{
		ft_putchar_fd(n + '0', 1);
		return (ft_ui_len(n));
	}
	else if (n >= 10)
	{
		ft_print_u(n / 10);
	}
	ft_putchar_fd(n % 10 + '0', 1);
	return (ft_ui_len(n));
}
