/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:37:18 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/02 17:20:36 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char *s, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	r;
	char	*p;

	j = 0 ;
	i = start ;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		p = ft_calloc(sizeof(char), 1);
		return (p);
	}
	if (ft_strlen(s + start) > len)
		r = len;
	else
		r = ft_strlen(s + start);
	p = ft_calloc(sizeof(char), r + 1);
	if (!p)
		return (NULL);
	while (j < r)
		*(p + j++) = *(s + i++);
	return (p);
}
