/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:07:25 by claprand          #+#    #+#             */
/*   Updated: 2024/10/21 15:06:38 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* get_env_size :
*		Recupere la taille de mon environnement.
*/
int	get_env_size(t_data	*data)
{
	int	len;

	len = 0;
	while (data->env[len])
		len++;
	return (len);
}

/* get_env :
*		Recupere mon environnement.
*		Recupere uniquement les variables d'env composee de la 
*		maniere suivante : key=value.
*/
char	*get_env(char *var_name, t_data	*data)
{
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(var_name);
	while (data->env[++i])
	{
		if (!ft_strncmp(data->env[i], var_name, len)
			&& data->env[i][len] == '=')
			return (data->env[i] + len + 1);
	}
	return (NULL);
}
