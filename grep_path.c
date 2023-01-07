/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:59:39 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/07 17:50:40 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**path_commend(char **envp)
{
	int		i;
	char	**path_for_env;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])) != NULL)
			break ;
		i++;
	}
	if (!envp[i])
	{
		ft_strerror("Path not found\n");
		exit(0);
	}
	path_for_env = ft_split(envp[i] + 5, ':');
	return (path_for_env);
}
