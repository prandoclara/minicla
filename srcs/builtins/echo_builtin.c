/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:29:10 by claprand          #+#    #+#             */
/*   Updated: 2024/10/21 14:36:35 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* has_opt :
*		Check si l'option "-n" est presente.
*/
static int	has_opt(char *s)
{
	int	i;

	i = 0;
	if (s[0] != '-')
		return (0);
	i++;
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

/* echo_builtin :
*		Execute la commande echo.
*/	
int	echo_builtin(t_data *data)
{
	int	i;
	int	opt;

	i = 1;
	opt = 0;
	while (data->cmd->args[i] != NULL && has_opt(data->cmd->args[i]) == 1)
	{
		opt = 1;
		i++;
	}
	while (data->cmd->args[i])
	{
		ft_putstr_fd(data->cmd->args[i], 1);
		if (data->cmd->args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!opt)
		ft_putstr_fd("\n", 1);
	return (0);
}
