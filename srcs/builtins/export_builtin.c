/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:50:08 by claprand          #+#    #+#             */
/*   Updated: 2024/10/21 15:03:56 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* parse_export :
*		Parse l'argument.
*		Check si c'est une lettre, un chiffre ou '_'.
*/
static int	parse_export(char *new_export_var)
{
	int		i;
	char	**new_var;

	new_var = ft_split(new_export_var, '=');
	i = -1;
	if (!new_var[0] || ft_strlen(new_var[0]) >= 50)
		return (freetab(new_var), 1);
	if (!ft_strcmp(new_var[0], "$?"))
		return (freetab(new_var), 0);
	if (ft_isalpha(new_var[0][0]) || new_var[0][0] == '_'
			|| ft_isdigit(new_var[0][0]))
	{
		if (ft_isdigit(new_var[0][0]))
			return (freetab(new_var), 1);
	}
	while (new_var[0][++i])
	{
		if (!ft_isalpha(new_var[0][i]) && new_var[0][i] != '_'
				&& !ft_isdigit(new_var[0][i]))
			return (freetab(new_var), 1);
	}
	return (freetab(new_var), 0);
}

/* append_variable_to_env :
*		Recupere l'env et ajoute la variable donnee a la fin de celui-ci.
*/
static int	append_variable_to_env(t_data *data, char *cmd)
{
	int		i;
	int		size;
	char	**new_env;

	i = -1;
	size = get_env_size(data);
	new_env = malloc(sizeof(char *) * (size + 2));
	if (!new_env)
	{
		return (1);
	}
	while (data->env[++i] != NULL)
	{
		new_env[i] = data->env[i];
	}
	new_env[i] = strdup(cmd);
	if (!new_env[i])
		return (free(new_env), 1);
	new_env[i + 1] = NULL;
	data->env = new_env;
	return (0);
}

/* update_or_add_env_var :
*		Ajoute ou met a jour la variable d'env.
*/
static int	update_or_add_env_var(t_data *data, char *cmd)
{
	int		i;
	char	**var;
	size_t	var_len;

	var = ft_split(cmd, '=');
	if (!var || !var[0])
		return (0);
	var_len = ft_strlen(var[0]);
	i = -1;
	while (data->env[++i])
	{
		if (!ft_strncmp(data->env[i], var[0], var_len)
			&& (data->env[i][var_len] == '='
			|| data->env[i][var_len] == '\0'))
		{
			if (!ft_strchr(cmd, '='))
				return (freetab(var), 0);
			free(data->env[i]);
			data->env[i] = ft_strdup(cmd);
			if (!data->env[i])
				return (freetab(var), 0);
			freetab(var);
			return (1);
		}
	}
	freetab(var);
	return (append_variable_to_env(data, cmd));
}

/* export_builtin :
*		execute la commande export avec ou sans argument. 
*		Parse d'abord la valeur passee en argument.
*		Si ok, on ajoute ou met a jour la variable d'env.
*/
int	export_builtin(t_data *data)
{
	int		i;
	char	**cmd;

	cmd = data->cmd->args;
	i = 0;
	if (!cmd[1])
	{
		execute_export_with_no_args(data);
		return (0);
	}
	while (cmd[++i])
	{
		if (parse_export(cmd[i]))
		{
			ft_fprintf(2, ERROR_EXPORT_ARG, cmd[i]);
			i++;
			continue ;
		}
		update_or_add_env_var(data, cmd[i]);
	}
	return (0);
}
