/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaldes <nbaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:09 by nbaldes           #+#    #+#             */
/*   Updated: 2025/08/01 16:43:18 by nbaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int argc, char **argv)
{
	//parsing
	//rediriger la lecture de ficher vers mon premier arg(fichier)
	//creer fork?
	//executer ma premiere commande sur ce fichier
	//stocker le resultat de la commande dans mon pipe
	//retourner dans outfile
	
}
// pid_t

int parsing(int argc, char **argv)
{
	//verifier qu il y as bien 4 args
	//verifier qu on peut open le premier file
	//??
	int infile;
	ssize_t 

	if (argc != 5)
		return (write(1, "Error\nWrong number of arguments\n", 33));
	infile = open(argv[1], O_RDONLY);
	if (!infile)
		return (write(1, "Error\nSomething went wrong with the infile\n", 43));
	
	read(infile, );
	
}