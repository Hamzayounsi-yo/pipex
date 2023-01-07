/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:35:30 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/07 11:28:15 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *s)
{
	int		i;
	int		s_len ;
	char	*p;

	i = 0;
	s_len = ft_strlen(s);
	p = malloc(sizeof(char) * s_len + 1);
	if (!p)
		return (NULL);
	while (*(s + i))
	{
		*(p + i) = *(s + i);
		i++;
	}
	*(p + i) = '\0';
	return (p);
}
