/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:05:52 by claprand          #+#    #+#             */
/*   Updated: 2024/10/01 11:00:06 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlen(const char *s);
int		strchr_gnl(char *s, char x);
char	*ft_join_gnl(char *s1, char *s2);
void	clean_gnl(char *line, char *buffer);
char	*get_next_line(int fd);

// int		ft_str_len(const char *s);
// char	*ft_str_chr(char *s, int c);
// char	*ft_strjoin_gnl(char *s1, char *s2);

#endif
