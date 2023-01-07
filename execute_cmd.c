/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:00:01 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/07 17:51:51 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *argv, char **envp)
{
	int		i;
	char	*cmd;
	char	**arg;
	char	**path;

	i = 0;
	cmd = ft_strdup(argv);
	path = path_commend(envp);
	arg = ft_split(argv, ' ');
	while (path[i])
	{
		if (ft_strnstr(cmd, "./", ft_strlen(argv)) != NULL)
			execve(cmd + 2, arg, path);
		else if (ft_strchr(argv, '/') == NULL)
		{
			free(cmd);
			cmd = ft_strjoin(path[i], arg[0]);
		}
		execve(cmd, arg, path);
		i++;
	}
	free2d(arg);
	free2d(path);
	free(cmd);
}
