/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utilisateur <utilisateur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:47:49 by nbaldes           #+#    #+#             */
/*   Updated: 2025/08/16 17:40:29 by utilisateur      ###   ########.fr       */
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
# include "printf/ft_printf.h"

typedef struct s_path
{
        char **path_cmd;
        int i_path_cmd;
}                                       t_path;

int	check_arg(int argc);
int main (int argc, char **argv, char **envp);
int parsing(int argc, char **argv, char **envp, t_path *path);
int	check_valid_infile(char **argv, char **path_cmd, t_path *path);
int outfile(int argc, char **argv, char **path_cmd, t_path *path);
char	**ft_split(char const *s, char c);
char ***get_command(int argc, char **argv);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char **find_path_split(char **envp);
char    *ft_strjoin(const char *s1, const char *s2);
char ***join_path_cmd(char ***splited_cmd, char **splited_path);
int check_access(char **path_cmd, t_path *path);
char    *ft_strdup(char *str);
void free_multi_tab(char ***multi_tab, char **tab);

#endif
