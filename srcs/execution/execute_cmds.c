/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:22:30 by claprand          #+#    #+#             */
/*   Updated: 2024/10/23 16:17:04 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* execute_system_binary :
*		Permet d'executer les commandes du systeme, type ls, cat, grep...
*/
static int	execute_system_binary(t_data *data, t_cmd *cmd)
{
	if (!cmd->command || cmd->command[0] == '\0')
		return (CMD_NOT_FOUND);
	cmd->path = get_cmd_path(data, cmd->command);
	if (!cmd->path)
		return (CMD_NOT_FOUND);
	if (execve(cmd->path, cmd->args, data->env) == -1)
		return (ft_fprintf(2, "Error execve\n"), 1);
	return (0);
}

/* setup_cmd_env :
*		Configure les descripteurs de fichier pour les pipes 
*		et les redirections d'entrées/sorties.
*/
static void	setup_cmd_env(t_data *data, t_cmd *cmd)
{
	if (cmd->prev && cmd->prev->pipe_output)
		do_pipe(data->cmd, data);
	if (cmd->io_fds)
		infile_outfile_redirections(cmd->io_fds);
	// close_fds(data->cmd);
}

/* handle_cmd_execution :
* 		Gère l'exécution d'une commande, en essayant d'abord les built-ins, 
*		puis les exécutables systèmes.
*/
static int	handle_cmd_execution(t_data *data, t_cmd *cmd)
{
	int	status;
	
	if (ft_strchr(cmd->command, '/') == NULL)
	{
		status = execute_builtin(data, cmd);
		if (status != CMD_NOT_FOUND)
			exit_shell(data, status);
		status = execute_system_binary(data, cmd);
		if (status != CMD_NOT_FOUND)
			return (status);
	}
	else
	{
		status = execve(cmd->command, cmd->args, data->env);
		if (status == -1)
		{
			ft_fprintf(2, "Execution error: %s\n", strerror(errno));
			return (1);
		}
	}
	return (status);
}

/* execute_cmds :
*		Exécute une commande en vérifiant les redirections et en gérant 
*		son environnement, puis termine le shell.
*/
int	execute_cmds(t_data *data, t_cmd *cmd)
{
	int	status;

	if (!cmd || !cmd->command)
	{
		ft_fprintf(2, "Error: No command found!\n");
		exit_shell(data, 1);
	}
	if (!valid_io_fds(cmd->io_fds))
		exit_shell(data, 1);
	setup_cmd_env(data, cmd);
	status = handle_cmd_execution(data, cmd);
	exit_shell(data, status);
	return (status);
}
