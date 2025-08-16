/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utilisateur <utilisateur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:24:43 by utilisateur       #+#    #+#             */
/*   Updated: 2025/08/16 18:16:30 by utilisateur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_arg(int argc)
{
	if (argc < 5)
	{
		errno = EINVAL;
		perror("Example: ./pipex file1 cmd1 cmd2 file2");
		return (1);
	}
	return (0);
}

int	check_valid_infile(char **argv, char **path_cmd, t_path *path)
{	
	if (access(argv[1], F_OK) == -1)
	{
		errno = ENOENT;
		perror(argv[1]);
		return (1);
	}
	if (access(argv[1], R_OK) == -1)
	{
		errno = EACCES;
		perror(argv[1]);
		return (1);
	}
	if (check_access(path_cmd, path))
		return (1);
	return (0);
}

int outfile(int argc, char **argv, char **path_cmd, t_path *path)
{
	int fd_outfile; 
	
	if (access(argv[argc - 1], F_OK) == -1)
	{
		fd_outfile = open(argv[argc - 1], O_CREAT, 0644);
        (void)fd_outfile;
		return (0);
	}
	if (access(argv[argc - 1], W_OK) == -1)
	{
		errno = EACCES;
		perror(argv[argc -1]);
		return (1);
	}
	if (check_access(path_cmd, path))
		return (1);
	return (0);
}

char ***get_command(int argc, char **argv)
{
	int i;
	char ***splited_cmd;
	
	i = 2;
	splited_cmd = malloc(sizeof(char **) * (argc - 1));
	if (!splited_cmd)
	return(NULL);
	while (i < argc - 1)
	{
		splited_cmd[i - 2] = ft_split(argv[i], ' ');
		i++;
	}
	splited_cmd[i - 2] = NULL;
	return(splited_cmd);
}

char **find_path_split(char **envp)
{
	char *full_path;
	int i;
	
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			full_path = envp[i] + 5;
			return (ft_split(full_path, ':'));
		}
		i++;
	}
	return (NULL);
}
