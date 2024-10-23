/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:29:05 by claprand          #+#    #+#             */
/*   Updated: 2024/10/23 16:20:14 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_command(t_cmd *cmd, t_data *data)
{
	if (cmd->path == NULL)
	{
		cmd->path = get_cmd_path(data, cmd->command);
		if (access(cmd->path, F_OK | X_OK) != 0)
		{
			ft_putstr_fd("minishell: command not found: ", 2);
			ft_putendl_fd(cmd->command, 2);
			return (EXIT_FAILURE);
		}
	}
	if (execve(cmd->path, cmd->args, data->env) == -1)
	{
		ft_putstr_fd("minishell: execution error: ", 2);
		ft_putendl_fd(cmd->command, 2);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

void setup_redirections(t_cmd *cmd)
{
	if (cmd->io_fds->infile)
	{
		cmd->io_fds->fd_in = open(cmd->io_fds->infile, O_RDONLY);
		if (cmd->io_fds->fd_in < 0)
			error_exit(EXIT_FAILURE, strerror(errno));
		dup2(cmd->io_fds->fd_in, STDIN_FILENO);
	}

	if (cmd->io_fds->outfile)
	{
		cmd->io_fds->fd_out = open(cmd->io_fds->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (cmd->io_fds->fd_out < 0)
			error_exit(EXIT_FAILURE, strerror(errno));
		dup2(cmd->io_fds->fd_out, STDOUT_FILENO);
	}
}

void	do_pipe(t_cmd *cmd, t_data *data)
{
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		error_exit(EXIT_FAILURE, strerror(errno));
	cmd->pipe_fd = p_fd;

	pid_t	pid = fork();
	if (pid == -1)
		error_exit(EXIT_FAILURE, strerror(errno));

	if (pid == 0)
	{
		close(p_fd[0]);
		dup2(p_fd[1], STDOUT_FILENO);
		setup_redirections(cmd);
		execute_command(cmd, data);
		close(p_fd[1]);
		exit(0);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
		close(p_fd[0]);
	}
}

void run_pipeline(t_data *data)
{
	t_cmd	*cmd = data->cmd;

	while (cmd)
	{
		if (cmd->next)
			do_pipe(cmd, data);
		else
		{
			setup_redirections(cmd);
			execute_command(cmd, data);
		}
		cmd = cmd->next;
	}
}
