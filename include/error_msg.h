/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:38:18 by claprand          #+#    #+#             */
/*   Updated: 2024/10/14 13:20:02 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# include "minishell.h"

# define ERROR_PWD "pwd: error retrieving current directory: \
	 getcwd: cannot access parent directories: No such file or directory\n"
# define ERROR_CD_HOME "minishell: cd: HOME not set\n"
# define ERROR_CD "minishell: cd: %s: No such file or directory\n"
# define ERROR_GETCWD "Error allocating using getcwd for cd ..\n"
# define ERROR_CD_TOO_MANY "minishell: cd: too many arguments\n"
# define ERROR_CD_DIR "minishell: cd: %s: No such file or directory\n"
# define ERROR_EXIT_ARG "minishell: exit: %s: numeric argument required\n"
# define ERROR_EXPORT_ARG "minishell: export: `%s': not a valid identifier\n"

#endif
