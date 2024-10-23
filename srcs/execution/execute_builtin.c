/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:11:35 by claprand          #+#    #+#             */
/*   Updated: 2024/10/22 15:11:16 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* execute_builtin :
*		Permet d'executer les builtins.
*/
int	execute_builtin(t_data *data, t_cmd *cmd)
{
	int	status;

	status = CMD_NOT_FOUND;
	if (ft_strncmp(*cmd->args, "cd", 3) == 0)
		status = cd_builtin(data);
	else if (ft_strncmp(*cmd->args, "echo", 5) == 0)
		status = echo_builtin(data);
	else if (ft_strncmp(*cmd->args, "env", 4) == 0)
		status = env_builtin(data);
	else if (ft_strncmp(*cmd->args, "export", 7) == 0)
		status = export_builtin(data);
	else if (ft_strncmp(*cmd->args, "pwd", 4) == 0)
		status = pwd_builtin();
	else if (ft_strncmp(*cmd->args, "unset", 6) == 0)
		status = unset_builtin(data);
	else if (ft_strncmp(*cmd->args, "exit", 5) == 0)
		status = exit_builtin(data);
	return (status);
}
