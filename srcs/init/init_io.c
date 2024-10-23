/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:15:06 by claprand          #+#    #+#             */
/*   Updated: 2024/10/22 14:33:18 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_io(t_io_fds *io_fds)
{
    io_fds->fd_in = -1;
    io_fds->fd_out = -1;
    io_fds->stdin = -1;
    io_fds->stdout = -1;
    io_fds->infile = NULL;
    io_fds->outfile = NULL;
}
