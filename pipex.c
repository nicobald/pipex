/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaldes <nbaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:09 by nbaldes           #+#    #+#             */
/*   Updated: 2025/08/08 18:05:52 by nbaldes          ###   ########.fr       */
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
int	parsing(int argc, char **argv)
{
	if (check_arg(argc))
		return (1);
	check_valid_infile(argv);
	outfile(argc, argv);
	return (0);
}
int	main(int argc, char **argv)
{
	if (parsing(argc, argv))
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