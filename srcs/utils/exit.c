/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:59:28 by claprand          #+#    #+#             */
/*   Updated: 2024/10/23 16:19:05 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(t_data *data, int exit_nb)
{
	if (data)
	{
		if (data->cmd && data->cmd->io_fds)
			close_fds(data->cmd);
		// free_data(data, 1);
	}
	exit(exit_nb);
}

void	error_exit(int code, char *message)
{
	ft_putstr_fd("pipex: ", 2);
	ft_fprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}