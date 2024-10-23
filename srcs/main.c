/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:06:23 by claprand          #+#    #+#             */
/*   Updated: 2024/10/23 16:03:10 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	main(int ac, char **av, char **envp)
// {
// 	char		*line = NULL;
// 	char 		**arg;
// 	t_data	data;
// 	t_cmd	cmd;
	
// 	(void)ac;
// 	init_data(&data, envp);
// 	init_cmd(&cmd, av);
// 	init_io(&cmd);
// 	data.cmd = &cmd;
// 	while (1)
// 	{
// 		line = readline(COLOR_PINK "minishell$ " COLOR_RESET);
// 		if (!line)
// 			exit(0);
// 		if (*line)
// 			add_history(line);
// 		else
// 		{
// 			free(line);
// 			continue ;
// 		}
// 		arg = ft_split(line, ' ');
// 		if (!arg || !arg[0])
// 		{
// 			free(line);
// 			if (arg) free(arg);
// 			continue ;
// 		}
// 		cmd.args = arg;
// 		cmd.command = arg[0];
// 		execute(&data);
// 	}
// 	clear_history();
// 	free(line);
// 	return (0);
// }

void	init_token_command_1(t_token *tok1)
{
	tok1->type = TOK_OR;
	tok1->index = 0;
	tok1->token = "test";
	tok1->prev = NULL;
	tok1->next = NULL;
}

void	init_cmd_1(t_data *data, t_cmd *cmd, t_io_fds *io)
{
	t_token *tok1;
	
	tok1 = malloc(sizeof(t_token));
	cmd->nb_redir = 1;
	init_token_command_1(tok1);
	cmd->redir = tok1;
	cmd->args = malloc(3 * sizeof(char *));
	cmd->args[0] = strdup("echo");
	cmd->args[1] = strdup("lol");
	cmd->args[2] = NULL; 
	cmd->command = cmd->args[0];
	data->cmd = cmd;
	cmd->io_fds = io;
	cmd->pipe_fd = NULL;
	cmd->pipe_output = 0;
	
	// printf("Command 1:\n");
	// for (int i = 0; cmd->args[i]; i++) {
	// 	printf("  Arg %d: %s\n", i, cmd->args[i]);
	// }
}

void	init_cmd_2(t_data *data, t_cmd *cmd, t_io_fds *io)
{
	cmd->nb_redir = 0;
	cmd->redir = NULL;
	cmd->args = malloc(sizeof(char *) * 3);
	cmd->args[0] = "cat";
	cmd->args[1] = "test";
	cmd->args[2] = NULL;
	cmd->command = cmd->args[0];
	data->cmd = cmd;
	cmd->io_fds = io;
	cmd->pipe_fd = NULL;
	cmd->pipe_output = 1;
	io->outfile = "test";
	
	// printf("Command 2:\n");
	// for (int i = 0; cmd->args[i]; i++) {
	// 	printf("  Arg %d: %s\n", i, cmd->args[i]);
	// }
}

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
    t_data data;
    t_cmd *cmd_1 = NULL;
	t_cmd *cmd_2 = NULL;
	t_io_fds io_fds;
	
    init_data(&data, envp);
	init_io(&io_fds);
    cmd_1 = malloc(sizeof(t_cmd));
    if (!cmd_1) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    cmd_2 = malloc(sizeof(t_cmd));
    if (!cmd_2) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
	data.nb_command = 2;
	data.input = "echo lol > test | cat test";

	init_cmd_1(&data, cmd_1, &io_fds);
	init_cmd_2(&data, cmd_2, &io_fds);
	cmd_1->prev = NULL;
	cmd_1->next = cmd_2;
	cmd_2->prev = cmd_1;
	cmd_2->next = NULL;
	data.cmd = cmd_1;
    execute(&data);
    return (0);
}
