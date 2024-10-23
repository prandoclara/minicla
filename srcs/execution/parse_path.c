/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:22:17 by claprand          #+#    #+#             */
/*   Updated: 2024/10/22 14:15:02 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* find_valid_cmd_path : 
* 		Cherche un chemin valide pour la commande en concaténant 
*		les chemins d'exécution et en vérifiant les permissions d'accès.
*/
static char	*find_valid_cmd_path(char *cmd, char **paths)
{
	int		i;
	char	*cmd_path;

	cmd_path = NULL;
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (!cmd_path)
		{
			ft_fprintf(2, "malloc: an unexpected error occured");
			return (NULL);
		}
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free_ptr(cmd_path);
		i++;
	}
	return (NULL);
}

/* get_path_from_env :
*		Récupère la liste des chemins d'exécution à 
*		partir de la variable d'environnement PATH.
*/
static char	**get_paths_from_env(t_data *data)
{
	char	**env_paths;
	char	*path_env;

	path_env = get_env("PATH", data);
	if (!path_env)
		return (NULL);
	env_paths = ft_split(path_env, ':');
	if (!env_paths)
		return (NULL);

	return (env_paths);
}

/* get_cmd_path :
*		Construit le chemin complet de la commande à exécuter 
*		en vérifiant les chemins d'exécution disponibles dans l'environnement.
*/
char	*get_cmd_path(t_data *data, char *name)
{
	char	**env_paths;
	char	*cmd;
	char	*cmd_path;

	if (!name)
		return (NULL);
	env_paths = get_paths_from_env(data);
	if (!env_paths)
		return (NULL);
	cmd = ft_strjoin("/", name);
	if (!cmd)
		return (free_str_tab(env_paths), NULL);
	cmd_path = find_valid_cmd_path(cmd, env_paths);
	if (!cmd_path)
	{
		free_ptr(cmd);
		free_str_tab(env_paths);
		return (NULL);
	}
	return (cmd_path);
}
