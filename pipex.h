/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utilisateur <utilisateur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:47:49 by nbaldes           #+#    #+#             */
/*   Updated: 2025/08/14 14:26:55 by utilisateur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

int	check_arg(int argc);
int main (int argc, char **argv, char **envp);
int parsing(int argc, char **argv, char **envp);
int	check_valid_infile(char **argv);
int outfile(int argc, char **argv);
char	**ft_split(char const *s, char c);
char ***get_command(int argc, char **argv);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char **find_path_split(char **envp);
char    *ft_strjoin(const char *s1, const char *s2);
char ***join_path_cmd(char ***splited_cmd, char **splited_path);

#endif
