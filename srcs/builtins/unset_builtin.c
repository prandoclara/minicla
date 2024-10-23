/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:06:32 by claprand          #+#    #+#             */
/*   Updated: 2024/10/21 15:06:05 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* unset_builtin :
*       Supprime une variable a l'env.
*/
int	unset_builtin(t_data *data)
{
	int	i;
	int	j;

	if (!data->cmd->args[1])
		return (1);
	i = 1;
	while (data->cmd->args[i])
	{
		j = 0;
		while (data->env[j])
		{
			if (!ft_strncmp(data->env[j], data->cmd->args[i], ft_strlen(data->cmd->args[i] + 1))
				&& (data->env[j][ft_strlen(data->cmd->args[i])] == '='
				|| data->env[j][ft_strlen(data->cmd->args[i])] == '\0'))
			{
				remove_env_var(data, data->cmd->args[i]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
