/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:52:47 by claprand          #+#    #+#             */
/*   Updated: 2024/10/21 15:20:36 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* cd_too_many :
*		Check le nombre d'arguments.
*/
static int	cd_too_many(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd->args[i])
	{
		if (i >= 2)
			return (1);
		i++;
	}
	return (0);
}

/* cd_home :
*		Met a jour le current working directory avec la valeur 
*		de la variable d'env HOME.
*/
static int	cd_home(t_data *data)
{
	char	*env_var;

	env_var = get_env("HOME", data);
	if (!env_var)
		return (ft_fprintf(2, ERROR_CD_HOME), 1);
	if (chdir(env_var))
		return (ft_fprintf(2, ERROR_CD, data->cmd->args[1]), 1);
	data->old_working_dir = data->working_dir;
	data->working_dir = getcwd(NULL, 0);
	return (0);
}

/* cd_point_point :
*		Recupere le current working directory auquel on supprime 
*		le dernier segment pour obtenir le previous directory.
*/
static int	cd_point_point(t_data *data)
{
	char	*env_var;

	env_var = remove_last_path_segment(getcwd(NULL, 0));
	if (!env_var)
		return (ft_fprintf(2, ERROR_GETCWD), 1);
	if (chdir(env_var) == -1)
		return (free(env_var), 1);
	data->old_working_dir = data->working_dir;
	data->working_dir = getcwd(NULL, 0);
	free(env_var);
	return (0);
}

/* cd_builtin :		
*		Execute la commande cd.
*/
int	cd_builtin(t_data *data)
{
	if (cd_too_many(data))
		return (ft_fprintf(2, ERROR_CD_TOO_MANY), 1);
	if (!data->cmd->args[1] || !ft_strncmp(data->cmd->args[1], "~", 2))
	{
		if (cd_home(data))
			return (0);
	}
	else if (!ft_strncmp(data->cmd->args[1], "..", 3))
	{
		if (cd_point_point(data))
			return (0);
	}
	else if (chdir(data->cmd->args[1]))
		return (ft_fprintf(2, ERROR_CD_DIR, data->cmd->args[1]), 1);
	data->old_working_dir = data->working_dir;
	data->working_dir = getcwd(NULL, 0);
	return (0);
}
