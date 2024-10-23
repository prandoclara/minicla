/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:59:21 by claprand          #+#    #+#             */
/*   Updated: 2024/10/21 14:40:24 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* pwd_builtin :
*		Obtient le current working directory avec getcwd.
*/
int	pwd_builtin(void)
{
	static char	buf[MAX_PWD] = {0};

	if (!getcwd(buf, MAX_PWD))
		return (ft_putendl_fd(ERROR_PWD, 2), 1);
	else
		ft_putendl_fd(buf, 1);
	return (0);
}
