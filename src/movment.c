/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:03:42 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/04 22:23:13 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rightmv(t_data *data)
{
	int	x;
	int	y;

	x = data->position.x;
	y = data->position.y;
	data->player_img = data->img.player;
	if (!foright(data, x, y))
		return ;
	if (data->map[y][x + 1] != '1' && data->map[y][x + 1] != '\0')
	{
		data->map[y][x] = '0';
		data->map[y][x + 1] = 'P';
		data->position.x = x + 1;
		rendermap(data);
	}
}

void	leftmv(t_data *data)
{
	int	x;
	int	y;

	x = data->position.x;
	y = data->position.y;
	data->player_img = data->img.player1;
	if (!forleft(data, x, y))
		return ;
	if (x - 1 >= 0 && data->map[y][x - 1] != '1')
	{
		data->map[y][x] = '0';
		data->map[y][x - 1] = 'P';
		data->position.x = x - 1;
		rendermap(data);
	}
}

void	upmv(t_data *data)
{
	int	x;
	int	y;

	x = data->position.x;
	y = data->position.y;
	data->player_img = data->img.player;
	if (!forup(data, x, y))
		return ;
	if (y - 1 >= 0 && data->map[y - 1][x] != '1')
	{
		data->map[y][x] = '0';
		data->map[y - 1][x] = 'P';
		data->position.y = y - 1;
		rendermap(data);
	}
}

void	downmv(t_data *data)
{
	int	x;
	int	y;

	x = data->position.x;
	y = data->position.y;
	data->player_img = data->img.player1;
	if (!fordown(data, x, y))
		return ;
	if (data->map[y + 1] && data->map[y + 1][x] != '1')
	{
		data->map[y][x] = '0';
		data->map[y + 1][x] = 'P';
		data->position.y = y + 1;
		rendermap(data);
	}
}

