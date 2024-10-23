/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:14:54 by claprand          #+#    #+#             */
/*   Updated: 2024/07/21 22:02:56 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h" 

int	ft_print_char(char c);
int	ft_print_int(int n);
int	ft_print_str(char *str);
int	ft_print_x(unsigned int x, char c, int *len);
int	ft_print_conversion(va_list	*arg, char *s, int i);
int	ft_printf(const char *s, ...);
int	ft_int_len(int n);
int	ft_hex_len(int n);
int	ft_print_u(unsigned int n);
int	ft_printux(unsigned int x, char c, int *len);
int	ft_print_pp(void *ptr, int *len);
int	ft_print_percent(char c);
int	ft_ui_len(unsigned int n);

#endif 