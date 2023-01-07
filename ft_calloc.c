/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:40:46 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/04 14:26:06 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	i;
	void	*p;

	i = 0;
	p = malloc(size * nitems);
	if (!p)
		return (NULL);
	while (i < nitems * size)
	{
		*(char *)(p + i) = '\0';
		i++;
	}
	return (p);
}
