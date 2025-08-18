/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utilisateur <utilisateur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:55:03 by utilisateur       #+#    #+#             */
/*   Updated: 2025/08/16 17:55:56 by utilisateur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int count_tab_line(char ***tab, char **line)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			i++;
		}
		return (i);
	}
	i = 0;
	if (line)
	{
		while (line[i])
		{
			i++;
		}
		return (i);
	}
	return (0);
}

char ***join_path_cmd(char ***splited_cmd, char **splited_path)
{
	char ***path_cmd;
	int i;
	int j;

	i = 0;
	path_cmd = malloc(sizeof(char **) * (count_tab_line(splited_cmd, NULL) + 1));
	if (!path_cmd)
		return(NULL);
	while (splited_cmd[i])
	{
		path_cmd[i] = malloc(sizeof(char *) * (count_tab_line(NULL, splited_path) + 1));
		if (!path_cmd)
			return(NULL);
		j = 0;
		while (splited_path[j])
		{
			path_cmd[i][j] = ft_strjoin(splited_path[j], splited_cmd[i][0]);
			j++;
		}
		path_cmd[i][j] = NULL;
		i++;
	}
	path_cmd[i] = NULL;
	return (path_cmd);
}

static char *copy_cmd_perror(char *path_cmd)
{
	int i;
	int j;
	int len;
	char *cmd;

	i = 0;
	j = 0;
	if (!path_cmd)
		return (NULL);
	while (path_cmd[i])
		i++;
	len = i;
	while (path_cmd[i] != '/')
		i--;
	cmd = malloc(sizeof(char) * (len + 1));
	if (!cmd)
		return (NULL);
	while (path_cmd[i++])
		cmd[j++] = path_cmd[i];
	cmd[j] = '\0';
	return (cmd);
}

void free_multi_tab(char ***multi_tab, char **tab)
{
    int i;
    int j;

    if (multi_tab)
    {
        i = -1;
        while (multi_tab[++i])
        {
            j = -1;
            while (multi_tab[i][++j])
                free(multi_tab[i][j]);
            free(multi_tab[i]);
        }
        free(multi_tab);
    }
    if (tab)
    {
        i = -1;
        while (tab[++i])
            free(tab[i]);
        free(tab);
    }
    return ;
}

int check_access(char **path_cmd, t_path *path)
{
	int i;
	char *tmp;

	i = -1;
	while (path_cmd[++i])
	{
			if (access(path_cmd[i], F_OK) == 0)
			{
				if (access(path_cmd[i], X_OK) == 0)
				{
					path->path_cmd[path->i_path_cmd++] = ft_strdup(path_cmd[i]);
					return (0);
				}
				errno = EACCES;
				tmp = copy_cmd_perror(path_cmd[i]);
				perror (tmp);
				free(tmp);
				return (1);
			}
	}
	errno = ENOENT;
	tmp = copy_cmd_perror(path_cmd[i - 1]);
	perror (tmp);
	free(tmp);
	return (1);
}
