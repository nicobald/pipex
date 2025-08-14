/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utilisateur <utilisateur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:09 by nbaldes           #+#    #+#             */
/*   Updated: 2025/08/12 18:22:48 by utilisateur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//test pour voir si je peux push????
// parsing
// rediriger la lecture de ficher vers mon premier arg(fichier)
// creer fork?
// executer ma premiere commande sur ce fichier
// stocker le resultat de la commande dans mon pipe
// retourner dans outfile
int	check_arg(int argc)
{
	if (argc != 5)
	{
		errno = EINVAL;
		perror("Example: ./pipex file1 cmd1 cmd2 file2");
		return (1);
	}
	return (0);
}

int	check_valid_infile(char **argv)
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
	return (0);
}

int outfile(int argc, char **argv)
{
	int fd_outfile; 

	if (access(argv[argc - 1], F_OK) == -1)
	{
		fd_outfile = open(argv[argc - 1], O_CREAT, 0644);
		return (fd_outfile);
	}
	if (access(argv[argc - 1], W_OK) == -1)
	{
		errno = EACCES;
		perror(argv[argc -1]);
		return (1);
	}
	return (0);
}
static void print_path(char **splited_path)
{
	int i;
	
	i = 0;
	while (splited_path[i])
	{
		printf("path number %i is %s\n", i, splited_path[i]);
		i++;
	}
	return ;
}

static void print_splited_cmd(char ***splited_cmd)
{
	int i;
	int j;
	
	i = 0;
	while (splited_cmd[i])
	{
		j = 0;
		while(splited_cmd[i][j])
		{
			printf("le tableau numero %i au mot numero %i stock %s\n", i, j, splited_cmd[i][j]);
			j++;
		}
		i++;
	}
	return ;
}

int	parsing(int argc, char **argv, char **envp)
{
	char ***splited_cmd;
	char **splited_path;

	if (check_arg(argc))
	return (1);
	check_valid_infile(argv);
	outfile(argc, argv);
	splited_cmd = get_command(argc, argv);
	print_splited_cmd(splited_cmd);
	splited_path = find_path_split(envp);
	print_path(splited_path);
	return (0);
}
char ***get_command(int argc, char **argv)
{
	int i;
	char ***splited_cmd;

	i = 2;
	splited_cmd = malloc(sizeof(char **) * (argc - 2));
	if (!splited_cmd)
	return(NULL);
	while (i > 1 && i < argc - 1)
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
int	main(int argc, char **argv, char **envp)
{
	if (parsing(argc, argv, envp))
	return (1);
}

//open
// pipe(); creation du pipe avant fork
// pipe handling
// int index_arg;
// index_arg = 3;
// if (!dup2(infile, 0));
// 	return (write (1, "Error\nSomething went wrong with the duplicate",
//));
// close(infile);
// while (index_arg > 2 && index_arg < argc - 1)
// {
	// 	fork();
	// 	index_arg++;
	// }