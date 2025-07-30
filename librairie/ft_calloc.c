/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:45:59 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/24 16:50:15 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*moncalloc;
	size_t	nbr;

	nbr = elementCount * elementSize;
	moncalloc = malloc(nbr);
	if (!moncalloc)
		return (NULL);
	ft_bzero(moncalloc, nbr);
	return (moncalloc);
}
