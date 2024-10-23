/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:51:40 by claprand          #+#    #+#             */
/*   Updated: 2024/10/23 16:21:00 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define COLOR_PINK "\033[1;35m"
# define COLOR_RESET "\033[0m"

# define LL_MAX 9223372036854775807ULL
# define MAX_PWD 2048

# define CMD_NOT_FOUND 127
# define CMD_NOT_EXECUTABLE 126

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h> 
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

# include "libft.h"
# include "error_msg.h"

typedef enum e_token_type
{
	//TOK_STR,
	TOK_IR,// <
	TOK_OR,// >
	TOK_APP,// >>
	TOK_HDOC,// <<
	TOK_PIPE,// |
	//TOK_COMMAND,
	//TOK_ARG,
	//TOK_FILE,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	int				index;
	char			*token;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_io_fds
{
	char			*infile;
	char			*outfile;
	int				fd_in;
	int				fd_out;
	int				stdin;
	int				stdout;
}	t_io_fds;

typedef struct t_cmd
{
	char			*command;
	char 			*name;
	char			**args;
	char			*path;
	int				pipe_output;
	int				*pipe_fd;
	t_io_fds		*io_fds;
	struct t_cmd	*next;
	struct t_cmd	*prev;
	int				index;
	int				nb_redir;
	struct s_token	*redir;
}	t_cmd;

typedef struct s_data
{
	int				nb_command;
	char			*input;
	char			**env;
	char			*working_dir;
	char			*old_working_dir;
	pid_t			pid;
	t_cmd			*cmd;
}	t_data;

/* ------------------------ EXECUTION ---------------------------------------*/

// builtin
int			env_builtin(t_data *data);
int			pwd_builtin(void);
int			echo_builtin(t_data *data);
int			cd_builtin(t_data *data);
int			exit_builtin(t_data *data);
void		execute_export_with_no_args(t_data *data);
int			export_builtin(t_data *data);
int			unset_builtin(t_data *data);

// utils
char		*remove_last_path_segment(char *path);
int			remove_env_var(t_data *data, char *var_name);

// env
char		*get_env(char *var_name, t_data *data);
int			get_env_size(t_data	*data);

// init
void		init_data(t_data *data, char **envp);
void		init_cmd(t_cmd *cmd, char **av);
void		init_io(t_io_fds *io_fds);

// execution 
int			execute_builtin(t_data *data, t_cmd *cmd);
int			execute_cmds(t_data *data, t_cmd *cmd);
char		*get_cmd_path(t_data *data, char *name);
int			execute(t_data *data);

// parse_path
char		*get_cmd_path(t_data *data, char *name);

// redirections
int			valid_io_fds(t_io_fds *io);
// void		close_pipe_fds(t_cmd *cmds, t_cmd *skip_cmd);
// int			create_pipes(t_data *data);
// int			set_pipe_fds(t_cmd *cmds, t_cmd *cur_cmd);
int			infile_outfile_redirections(t_io_fds *io);
int			save_io_fds(t_io_fds *io);
int			clear_io_fds(t_io_fds *io);

// utils
void		free_ptr(void *ptr);
void		free_str_tab(char **tab);
void		exit_shell(t_data *data, int exit_nb);
void		close_fds(t_cmd *cmd);


int	execute_command(t_cmd *cmd, t_data *data);
void setup_redirections(t_cmd *cmd);
void	do_pipe(t_cmd *cmd, t_data *data);
void run_pipeline(t_data *data);
void	error_exit(int code, char *message);

#endif 