/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:32:37 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/02 12:57:03 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_collectibles(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'C')
			{
					data->cnt.tot_collect++;
			}
		}
		y++;
	}
}

void	ft_inicnt(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	free((data->cnt.coins = 0, data->cnt.exit = 0, data->cnt.player = 0,
			data->position.x = 0, data->position.y = 0, NULL));
	data->cnt.collected = 0;
	data->cnt.tot_collect = 0;
	count_collectibles(data);
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
}
