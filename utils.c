/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utilisateur <utilisateur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:01:21 by utilisateur       #+#    #+#             */
/*   Updated: 2025/08/14 14:11:36 by utilisateur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t  ft_strlen(const char *str)
{
        size_t  i;

        i = 0;
		if (str)
		{
			while (str[i])
					i++;
		}
        return (i);
}

static void    ft_strjoin_copy(char *result, const char *s1, const char *s2)
{
        int     i;
        int     j;

        i = 0;
        j = 0;
        while (s1[i])
        {
                result[i] = s1[i];
                i++;
        }
        result[i] = '/';
        i++;
        while (s2[j])
        {
                result[i + j] = s2[j];
                j++;
        }
        result[i + j] = '\0';
}

char    *ft_strjoin(const char *s1, const char *s2)
{
        char    *result;
        int             lentot;

        if (!s1)
                s1 = "";
        if (!s2)
                s2 = "";
        lentot = ft_strlen(s1) + ft_strlen(s2);
        result = malloc(lentot + 1);
        if (!result)
                return (NULL);
        ft_strjoin_copy(result, s1, s2);
        return (result);
}

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        size_t  i;

        i = 0;
        while ((s1[i] || s2[i]) && (i < n))
        {
                if (s1[i] == s2[i])
                        i++;
                else
                        return (s1[i] - s2[i]);
        }
        return (0);
}
