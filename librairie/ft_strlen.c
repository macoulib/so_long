/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:16:42 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/21 15:12:42 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include  "../src/so_long.h"

size_t	ft_strlen( const char *theString )
{
	size_t	i;

	i = 0;
	while (theString[i])
		i++;
	return (i);
}
