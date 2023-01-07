/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:23:43 by hyounsi           #+#    #+#             */
/*   Updated: 2023/01/07 17:50:27 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(char *arr)
{
	size_t	len;

	len = 0 ;
	if (!arr)
		return (0);
	while (arr[len])
		len++;
	return (len);
}

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len_little ;

	i = 0;
	if (!big && len == 0)
		return (NULL);
	len_little = ft_strlen(little);
	if (len_little == 0)
		return ((char *)big);
	while (*(big + i) && i < len)
	{
		j = 0;
		k = i;
		while (*(big + k + j) == *(little + j) && *(big + k + j) && k + j < len)
		{
			j++;
			if (len_little == j)
				return ((char *)big + k);
		}
		i++;
	}
	return (NULL);
}
