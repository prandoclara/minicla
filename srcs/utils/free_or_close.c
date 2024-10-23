/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_or_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:54:19 by claprand          #+#    #+#             */
/*   Updated: 2024/10/23 16:21:09 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_ptr(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_str_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free_ptr(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	close_fds(t_cmd *cmd)
{
	if (cmd->io_fds)
	{
		if (cmd->io_fds->fd_in != -1)
			close(cmd->io_fds->fd_in);
		if (cmd->io_fds->fd_out != -1)
			close(cmd->io_fds->fd_out);
	}
	// close_pipe_fds(cmd, NULL);
}
