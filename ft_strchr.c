/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:35:27 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/07 11:28:07 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strchr( const char *str, int c)
{
	int	i;

	i = 0;
	while (*str != (char)c)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *)str);
}
