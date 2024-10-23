/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:10:30 by claprand          #+#    #+#             */
/*   Updated: 2024/10/21 14:41:29 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* remove_last_path_segment
*		supprime le dernier segment d'un path.
*		exemple : home/claprand/Documents = home/claprand
*/
char	*remove_last_path_segment(char *path)
{
	int	i;
	int	len;

	len = ft_strlen(path);
	if (len > 0 && path[len - 1] == '/')
		len--;
	i = len - 1;
	while (i >= 0)
	{
		if (path[i] == '/')
		{
			if (i == 0)
				path[i + 1] = '\0';
			else
				path[i] = '\0';
			break ;
		}
		i--;
	}
	return (path);
}

/* remove_env_var : 
*		Supprime une variable d'env, parcourt tout l'env pour trouver
*		la variable donnee, si elle existe, la fonction copie tout ce qu'elle
*		trouve avant la variable donne, saute cette variable, et copie tout le
*		reste. 
*/	
int	remove_env_var(t_data *data, char *var_name)
{
	int		i;
	int		j;
	int		size;
	char	**new_env;

	size = get_env_size(data);
	i = 0;
	while (data->env[++i])
	{
		if (!ft_strncmp(data->env[i], var_name, ft_strlen(var_name + 1)))
		{
			new_env = malloc(sizeof(char *) * size);
			if (!new_env)
				return (1);
			j = -1;
			while (++j < i)
				new_env[j] = data->env[j];
			j = i + 1;
			while (++j < size)
				new_env[j - 1] = data->env[j];
			free(data->env[i]);
			free(data->env);
			data->env = new_env;
			return (0);
		}
	}
	return (1);
}
