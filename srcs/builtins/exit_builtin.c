/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:18:59 by claprand          #+#    #+#             */
/*   Updated: 2024/10/21 15:04:56 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* ft_a_to_ull :
*		Array to unsigned long long.
*/
static long long	ft_a_to_ull(char *str)
{
	int					i;
	int					sign;
	unsigned long long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
		if ((sign == 1 && nb > LLONG_MAX)
			|| (sign == -1 && nb > (unsigned long long)LLONG_MAX + 1))
			return (free(str), ft_fprintf(2, "Error ft_a_to_ull\n"), 1);
	}
	return (free(str), (long long)(nb * sign));
}

/* exit_builtin :
*		Execute la commande exit. Print exit, s'il n'y a pas d'arg exit = 0.
*		si l'argument n'est ni un chiffre ni une lettre exit = 2.
*		Autrement la valeur de sortie est recuperer avec ft_a_to_ull.
*/
int	exit_builtin(t_data *data)
{
	long long	value;
	int			i;

	printf("exit\n");
	if (!data->cmd->args[1])
		exit(0);
	i = -1;
	while (data->cmd->args[1][++i])
	{
		if (!ft_issign(data->cmd->args[1][i])
			&& !ft_isdigit(data->cmd->args[1][i]))
		{
			ft_fprintf(2, ERROR_EXIT_ARG, data->cmd->args[1]);
			exit(2);
		}
	}
	value = ft_a_to_ull(data->cmd->args[1]);
	exit(value);
}
