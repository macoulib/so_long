/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:32:37 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/01 22:47:08 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_inicnt(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->cnt.coins = 0;
	data->cnt.exit = 0;
	data->cnt.player = 0;
	data->position.x = 0;
	data->position.y = 0;
	data->cnt.collected = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->position.x = x;
				data->position.y = y;
			}
			x++;
		}
		y++;
	}
	// printf("%d %d \n",  data->position.x  , data->position.y) ;
}
