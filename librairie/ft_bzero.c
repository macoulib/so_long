/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:24:50 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/24 16:54:54 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*scpy;
	size_t			i;

	i = 0 ;
	scpy = (unsigned char *) s;
	while (n > i)
	{
		scpy[i] = '\0';
		i++;
	}
}
