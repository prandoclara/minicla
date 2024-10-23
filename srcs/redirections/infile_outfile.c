/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile_outfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:04:57 by claprand          #+#    #+#             */
/*   Updated: 2024/10/21 15:10:03 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* clear_io_fds :
*		Restaure les descripteurs d'entrée et de sortie standard
*		à leur état initial et ferme les descripteurs sauvegardés.
*/	
int	clear_io_fds(t_io_fds *io)
{
	if (!io)
		return (1);
	if (io->stdin != -1)
	{
		if (dup2(io->stdin, STDIN_FILENO) == -1)
			return (1);
		close(io->stdin);
		io->stdin = -1;
	}
	if (io->stdout != -1)
	{
		if (dup2(io->stdout, STDOUT_FILENO) == -1)
			return (1);
		close(io->stdout);
		io->stdout = -1;
	}
	return (0);
}

/* save_io_fds :
* 		Sauvegarde les descripteurs d'origine.
*/
int	save_io_fds(t_io_fds *io)
{
	if (!io)
		return (1);
	io->stdin = dup(STDIN_FILENO);
	if (io->stdin == -1)
	{
		ft_fprintf(2, "Error : stdin dup\n");
		return (1);
	}
	io->stdout = dup(STDOUT_FILENO);
	if (io->stdout == -1)
	{
		ft_fprintf(2, "Error : stdout dup\n");
		return (1);
	}
	return (0);
}

/* infile_outfile_redirections :
* 		Sauvegarde les descripteurs d'origine et redirige l'entrée et la sortie 
* 		standard vers les fichiers spécifiés dans les redirections.
*/
int	infile_outfile_redirections(t_io_fds *io)
{
	if (!io)
		return (1);
	save_io_fds(io);
	if (io->fd_in != -1)
		if (dup2(io->fd_in, STDIN_FILENO) == -1)
			return (ft_fprintf(2, "error dup2: fd_in\n"));
	if (io->fd_out != -1)
		if (dup2(io->fd_out, STDOUT_FILENO) == -1)
			return (ft_fprintf(2, "error dup2: fd_out\n"));
	return (1);
}

/* valid_io_fds :
* 		Vérifie si les descripteurs d'entrée et 
*		de sortie spécifiés sont valides.
*/
int	valid_io_fds(t_io_fds *io)
{
	if (!io || (!io->infile && !io->outfile))
		return (1);
	if ((io->infile && io->fd_in == -1) || (io->outfile && io->fd_out == -1))
		return (1);
	return (0);
}
