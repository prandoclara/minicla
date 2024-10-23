/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:24:39 by claprand          #+#    #+#             */
/*   Updated: 2024/04/20 13:50:35 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		len = 6;
		return (len);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen((char *)str));
}
