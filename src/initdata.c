/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:32:37 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/21 01:09:50 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	surrounded(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'C')
	{
		data->cnt.tot_collect++;
		if (data->map[y][x + 1] == '1' && data->map[y][x - 1] == '1'
			&& data->map[y + 1][x] == '1' && data->map[y - 1][x] == '1')
		{
			ft_error("❌ Pas d’accès à l’objet :..", data);
		}
	}
	if (data->map[y][x] == 'E')
	{
		data->cnt.tot_collect++;
		if (data->map[y][x + 1] == '1' && data->map[y][x - 1] == '1'
			&& data->map[y + 1][x] == '1' && data->map[y - 1][x] == '1')
		{
			ft_error("❌ Pas d’accès à la porte :..", data);
		}
	}
}
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
			surrounded(data, x, y);
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

void	exitacces(t_data *data, int height)
{
	int	x;
	int	y;
	int	width;
	int	mur;

	while (data->map[height])
		height++;
	width = ft_strlen(data->map[0]);
	x = 0;
	while (++x < width - 1)
	{
		mur = 1;
		y = -1;
		while (++y < height)
		{
			if (data->map[y][x] != '1')
			{
				mur = 0;
				break ;
			}
		}
		if (mur)
			ft_error("❌ Mur vertical détecté hors bordure.", data);
	}
}
