/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:55:25 by claprand          #+#    #+#             */
/*   Updated: 2024/04/04 14:56:20 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_atoi converts a string into an int.

	RETURN VALUE :
	The converted int.
*/

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

/*
#include <stdio.h>
int main(void)
{
	char str1[] = "+123";
	char str2[] = "-456";
	char str3[] = "0";
	char str4[] = "";

	printf("%d\n", ft_atoi(str1));
	printf("%d\n", ft_atoi(str2));
	printf("%d\n", ft_atoi(str3));
	printf("%d\n", ft_atoi(str4));
	printf("%d\n", ft_atoi("\n\n\n  -46\b9 \n5d6"));
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", ft_atoi("-47-5"));
	printf("%d\n", ft_atoi("--47"));
	printf("%d\n", ft_atoi("-+48"));
	printf("%d\n", ft_atoi("-4886"));
	printf("\n");
	printf("%d\n", atoi(str1));
	printf("%d\n", atoi(str2));
	printf("%d\n", atoi(str3));
	printf("%d\n", atoi(str4));
	printf("%d\n", atoi("\n\n\n  -46\b9 \n5d6"));
	printf("%d\n", atoi("-2147483648"));
	printf("%d\n", atoi("-47-5"));
	printf("%d\n", atoi("--47"));
	printf("%d\n", atoi("-+48"));
	printf("%d\n", atoi("-4886"));
	return (0);
}
*/