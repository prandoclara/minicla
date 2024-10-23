/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:22:21 by claprand          #+#    #+#             */
/*   Updated: 2024/10/23 16:21:59 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* wait_for_children :
*		Attend la fin de tous les processus enfants et 
*		récupère le statut du dernier enfant exécuté.
*/
static int	wait_for_children(t_data *data)
{
	pid_t	child_pid;
	int		status;
	int		save_status;

	close_fds(data->cmd);
	save_status = 0;
	while ((child_pid = waitpid(-1, &status, 0)) != -1 || errno != ECHILD)
	{
		if (child_pid == data->pid)
			save_status = status;
	}
	if (WIFSIGNALED(save_status))
		status = 128 + WTERMSIG(save_status);
	else if (WIFEXITED(save_status))
		status = WEXITSTATUS(save_status);
	else
		status = save_status;
	return (status);
}

/* create_children :
*		Crée un processus enfant pour chaque commande dans la 
*		liste et exécute la commande associée.
*/
static int	create_children(t_data *data)
{
	t_cmd	*cmd;

	cmd = data->cmd;
	while (cmd)
	{
		data->pid = fork();
		if (data->pid == -1)
			return (ft_fprintf(2, "Error fork"), 1);
		else if (data->pid == 0)
			execute_cmds(data, cmd);
		cmd = cmd->next;
	}
	return (wait_for_children(data));
}

/* setup_exec_env :
* 		Prépare l'environnement d'exécution en vérifiant les pipes 
*		et la validité des descripteurs d'entrée/sortie.
*/
static int	setup_exec_env(t_data *data)
{
	if (!data || !data->cmd)
		return (0);
	if (!data->cmd->command)
	{
		if (data->cmd->io_fds && !valid_io_fds(data->cmd->io_fds))
			return (1);
		return (0);
	}
	do_pipe(data->cmd, data);
	return (CMD_NOT_FOUND);
}

/* handle_exec :
* 		Exécute une commande sans pipe si les 
*		redirections d'entrées/sorties sont valides.
*/
static int	handle_exec(t_data *data)
{
	if (!data->cmd->pipe_output && !data->cmd->prev
		&& valid_io_fds(data->cmd->io_fds))
	{
		infile_outfile_redirections(data->cmd->io_fds);
		return (execute_builtin(data, data->cmd));
		clear_io_fds(data->cmd->io_fds);
	}
	return (CMD_NOT_FOUND);
}

/* execute :
*		Fonction principale pour exécuter les commandes en 
*		préparant l'environnement, en gérant l'exécution des 
*		built-ins, et en créant des processus enfants si nécessaire.
*/	
int	execute(t_data *data)
{
	int	return_value;
	
	return_value = setup_exec_env(data);
	if (return_value != CMD_NOT_FOUND)
		return (return_value);
	return_value = handle_exec(data);
	if (return_value != CMD_NOT_FOUND)
		return (return_value);
	return (create_children(data));
}
