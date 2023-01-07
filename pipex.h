/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:24:27 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/07 21:02:08 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *arr);
char	*ft_strnstr(char *big, char *little, size_t len);
char	*ft_substr(char *s, size_t start, size_t len);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strjoin(char *s1, char *s2);
void	execute_cmd(char *argv, char **envp);
char	**path_commend(char **envp);
int		check_cmd(char **envp, char **argv);
int		ft_strerror(char *message);
char	*ft_strchr( const char *str, int c);
char	*ft_substr(char *s, size_t start, size_t len);
char	*ft_strdup(char *s);
void	free2d(char **arr);
#endif