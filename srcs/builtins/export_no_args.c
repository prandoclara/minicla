/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_no_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:17:36 by claprand          #+#    #+#             */
/*   Updated: 2024/10/21 14:40:19 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* sort_index :
*		Nous permet de trier nos valeurs. 
*/
static void	sort_index(char **tab, int *index, int size)
{
	int	i;
	int	j;
	int	min_index;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(tab[index[j]], tab[index[min_index]]) < 0)
				min_index = j;
			j++;
		}
		tmp = index[i];
		index[i] = index[min_index];
		index[min_index] = tmp;
		i++;
	}
}

/* print_export :
*		Permet d'afficher les variables d'env.
*		key= ou key=value
*
*/
static void	print_export(char **tab, int *index, int size)
{
	int		i;
	char	*sub;
	char	**split;

	i = -1;
	while (++i < size)
	{
		sub = ft_strchr(tab[index[i]], '=');
		if (sub)
		{
			split = ft_split(tab[index[i]], '=');
			printf("export %s=\"%s\"\n", split[0], sub + 1);
			freetab(split);
		}
		else
		{
			printf("export %s\n", tab[index[i]]);
		}
	}
}

/* execute_export_with_no_args :
*		Execute export seul, sans argument, en triant les donnees 
*		par ordre alphabetique ascii.
*/	
void	execute_export_with_no_args(t_data *data)
{
	int		i;
	int		size;
	int		*index;

	i = 0;
	size = get_env_size(data);
	index = malloc(sizeof(int) * (size + 1));
	if (!index)
	{
		free(data->env);
		return ;
	}
	while (i < size)
	{
		index[i] = i;
		i++;
	}
	sort_index(data->env, index, size);
	print_export(data->env, index, size);
	free(index);
}
