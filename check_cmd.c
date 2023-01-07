/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:00:06 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/07 21:12:07 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

int	free_help(char **c, char *cmd, int number)
{
	free(cmd);
	free2d(c);
	return (number);
}

int	cmd_x(char **path, char *argv)
{
	int		i;
	char	*cmd;
	char	**c;

	i = 0;
	cmd = ft_strdup(argv);
	c = ft_split(argv, ' ');
	while (path[i])
	{
		if (ft_strnstr(argv, "./", ft_strlen(argv)) && access(cmd, F_OK) == 0)
			return (free_help(c, cmd, 1));
		if (ft_strchr(argv, '/') == NULL)
		{
			free(cmd);
			cmd = ft_strjoin(path[i], c[0]);
		}
		if (access(cmd, F_OK) == 0)
			return (free_help(c, cmd, 1));
		i++;
	}
	return (free_help(c, cmd, 0));
}

int	check_cmd(char **envp, char **argv)
{
	char	**path;

	path = path_commend(envp);
	if (cmd_x(path, argv[2]) == 0)
		ft_strerror("cmd 1 not found\n");
	if (cmd_x(path, argv[3]) == 0)
		ft_strerror("cmd 2 not found\n");
	free2d(path);
	return (0);
}
