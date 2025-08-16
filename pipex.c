/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utilisateur <utilisateur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:38:09 by nbaldes           #+#    #+#             */
/*   Updated: 2025/08/16 18:18:49 by utilisateur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// rediriger la lecture de ficher vers mon premier arg(fichier)
// creer fork?
// executer ma premiere commande sur ce fichier
// stocker le resultat de la commande dans mon pipe
// retourner dans outfile

static int init_path(t_path *path, int argc)
{
	path->i_path_cmd = 0;
	path->path_cmd = malloc(sizeof(char *) * (argc - 2));
	if (!path->path_cmd)
		return (1);
	return (0);
}

int	parsing(int argc, char **argv, char **envp, t_path *path)
{
	char ***splited_cmd;
	char ***path_cmd;
	char **splited_path;
	int status;
	int i;

	i = 0;
	status = 0;
	if (check_arg(argc))
		return (1);
	splited_cmd = get_command(argc, argv);
	splited_path = find_path_split(envp);
	path_cmd = join_path_cmd(splited_cmd, splited_path);
	free_multi_tab(splited_cmd, splited_path);
	if (check_valid_infile(argv, path_cmd[0], path))
		status = 1;
	while (++i < (argc - 4))
		if (check_access(path_cmd[i], path))
			status = 1;
	if (outfile(argc, argv, path_cmd[argc - 4], path))
		status = 1;
	path->path_cmd[path->i_path_cmd] = NULL;
	free_multi_tab(path_cmd, NULL);
	return (status);
}

// static void print_path (t_path *path)
// {
// 	int i;

// 	i = 0;
// 	while(path->path_cmd[i])
// 	{
// 		printf(" le chemin %i stock le chemin %s\n", i, path->path_cmd[i]);
// 		i++;
// 	}
// 	return ;
// }

int	main(int argc, char **argv, char **envp)
{
	t_path path;

	init_path(&path, argc);
	if (parsing(argc, argv, envp, &path))
	{
		free_multi_tab(NULL, path.path_cmd);
		return (1);
	}
	// print_path(&path);
	return (0);
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