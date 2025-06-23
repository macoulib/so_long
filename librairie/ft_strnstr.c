/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:34:31 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/21 15:12:46 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include  "../src/so_long.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	little_len;

	i = 0;
	j = 0;
	k = 0;
	little_len = ft_strlen(little);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i])
	{
		while (big[i + j] == little[k] && i + j < len && little[k] != '\0')
		{
			if (k == little_len - 1)
				return ((char *) big + i);
			k++;
			j++;
		}
		k = 0;
		j = 0;
		i++;
	}
	return (NULL);
}
