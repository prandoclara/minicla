/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:38:11 by claprand          #+#    #+#             */
/*   Updated: 2024/10/22 15:16:35 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_cmd(t_cmd *cmd, char **av)
{
	(void)av;
    cmd->command = NULL;
    cmd->args = (char *[]){"echo", "clara", NULL};
    cmd->path = NULL;
    cmd->pipe_output = 0;
    cmd->pipe_fd = NULL;
    cmd->io_fds = malloc(sizeof(t_io_fds));
    if (cmd->io_fds)
        init_io(cmd->io_fds);
    cmd->next = NULL;
    cmd->prev = NULL;
    cmd->index = 0;
    cmd->nb_redir = 0;
    cmd->redir = NULL;
}
