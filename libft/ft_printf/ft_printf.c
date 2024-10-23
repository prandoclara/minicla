/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:14:50 by claprand          #+#    #+#             */
/*   Updated: 2024/07/21 22:02:45 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_conversion(va_list	*arg, char *s, int i)
{
	int	len;

	len = 0;
	if (s[i] == 'c')
		len = ft_print_char((int)va_arg(*arg, int));
	else if (s[i] == 's')
		len = ft_print_str((char *)va_arg(*arg, char *));
	else if (s[i] == 'd' || s[i] == 'i')
		len = ft_print_int((int)va_arg(*arg, int));
	else if (s[i] == 'x')
		len = ft_print_x((unsigned int)va_arg(*arg, unsigned int), s[i], &len);
	else if (s[i] == 'X')
		len = ft_printux((unsigned int)va_arg(*arg, unsigned int), s[i], &len);
	else if (s[i] == 'p')
		len = ft_print_pp((void *)va_arg(*arg, void *), &len);
	else if (s[i] == 'u')
		len = ft_print_u((unsigned int)va_arg(*arg, unsigned int));
	else if (s[i] == '%')
		len = ft_print_percent('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = -1;
	len = 0;
	va_start(arg, s);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_print_conversion(&arg, (char *)s, i);
			continue ;
		}
		else
			len += ft_print_char(s[i]);
	}
	va_end(arg);
	return (len);
}

int	ft_fprintf(int fd, const char *str, ...)
{
	va_list	args;
	int		i;
	int		printed_char_nb;

	i = 0;
	printed_char_nb = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printed_char_nb += ft_print_conversion(&args, (char *)str, i + 1);
			i++;
		}
		else
		{
			printed_char_nb++;
			ft_putchar_fd(str[i], fd);
		}
		i++;
	}
	va_end(args);
	return (printed_char_nb);
}
