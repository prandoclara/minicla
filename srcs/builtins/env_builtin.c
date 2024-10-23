/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:57:08 by claprand          #+#    #+#             */
/*   Updated: 2024/10/22 15:11:56 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* contains_equal :
*		Check s'il y a un egal, si oui cela signifie que la variable
*		d'env est bien constituee donc on peut la recuperer.
*		key=value
*/

static int	contains_equal(char *s)
{
	while (*s)
	{
		if (*s == '=')
			return (1);
		s++;
	}
	return (0);
}

/* env_builtin :
*		Execute la commande env. Recupere toutes les valeurs avec un '='.
*/
int	env_builtin(t_data *data)
{
	int	i;

	i = -1;
	while (data->env[++i])
	{
		if (contains_equal(data->env[i]))
			ft_printf("%s\n", data->env[i]);
	}
	return (0);
}
