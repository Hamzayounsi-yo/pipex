/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 09:42:36 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/07 21:01:42 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	child_process(int f1, int *fd, char **envp, char **argv)
{
	if (f1 != -1)
	{
		dup2(f1, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(f1);
		execute_cmd(argv[2], envp);
	}
}

void	parent_process(int f2, int *fd, char **envp, char **argv)
{
	wait(0);
	dup2(f2, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(f2);
	execute_cmd(argv[3], envp);
}

int	ft_strerror(char *message)
{
	int	i;

	i = 0;
	while (message[i])
		write(2, &message[i++], 1);
	return (0);
}

int	main(int argc, char **argv, char *envp[])
{
	int	fd[2];
	int	f1;
	int	f2;
	int	id;

	if (argc != 5)
		return (ft_strerror("you must enter 4 arguments\n"));
	f1 = open(argv[1], O_RDONLY);
	if (f1 == -1)
		ft_strerror("error in infile\n");
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	check_cmd(envp, argv);
	if (pipe(fd) == -1)
		return (ft_strerror("pipe not work\n"));
	id = fork();
	if (id < 0)
		return (ft_strerror("fork not work\n"));
	if (id == 0)
		child_process(f1, fd, envp, argv);
	else
		parent_process(f2, fd, envp, argv);
}
