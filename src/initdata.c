/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:32:37 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/18 21:47:03 by macoulib         ###   ########.fr       */
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

int	init_enemy(t_data *data)
{
	int	x;
	int	y;
	int	j;

	x = 0;
	y = 0;
	j = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'T')
			{
				data->eposition.x = x;
				data->eposition.y = y;
				j = 1;
			}
			x++;
		}
		y++;
	}
	return (j);
}

void	ft_inicnt(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	free((data->cnt.coins = 0, data->cnt.exit = 0, data->cnt.player = 0,
			data->position.x = 0, data->position.y = 0, NULL));
	data->cnt.mvt = 0;
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
	init_enemy(data);
}
