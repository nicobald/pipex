/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaldes <nbaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:09 by nbaldes           #+#    #+#             */
/*   Updated: 2025/08/07 13:49:26 by nbaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int argc, char **argv)
{
	parsing(argc, argv);
	//parsing
	//rediriger la lecture de ficher vers mon premier arg(fichier)
	//creer fork?
	//executer ma premiere commande sur ce fichier
	//stocker le resultat de la commande dans mon pipe
	//retourner dans outfile
}

void parsing(int argc, char **argv)
{
	//verifier qu il y as bien 4 args
	//verifier qu on peut open le premier file
	//??
	int infile;
	// int index_arg;
	int outfile;
	(void)argc;
	// index_arg = 3;
	if (argc != 5)
	{
		errno = EINVAL;
		return (perror("Exemple: ./pipex file1 cmd1 cmd2 file2"));
	}
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		errno = ENOENT;
		return (perror(argv[1]));
	}
	outfile = open(argv[argc - 1], O_RDONLY);
	if (outfile == -1)
		return (perror(argv[argc - 1]));
	// if (!access(argv[1], R_OK))
	// 	return (write(1, "Error\nWrong access permission to infile\n", 40));
	// if (!dup2(infile, 0));
	// 	return (write (1, "Error\nSomething went wrong with the duplicate", 45));
	// close(infile);
	// pipe(); creation du pipe avant fork
	// while (index_arg > 2 && index_arg < argc - 1)
	// {
	// 	fork();
	// 	index_arg++;
	// }
} 