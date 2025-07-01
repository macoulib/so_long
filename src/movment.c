/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:03:42 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/01 22:43:16 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rightmv(t_data *data)
{
	int	x;
	int	y;

	x = data->position.x;
	y = data->position.y;
	// Vérifie que x + 1 est dans la limite de la largeur de la map
	if (data->map[y][x + 1] != '1' && data->map[y][x + 1] != '\0')
	{
		data->map[y][x] = '0';
		data->map[y][x + 1] = 'P';
		data->position.x = x + 1;
		x = data->position.x;
		if (x == 'E' && )
			rendermap(data);
	}
}

void	leftmv(t_data *data)
{
	int	x;
	int	y;

	x = data->position.x;
	y = data->position.y;
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
	if (data->map[y + 1] && data->map[y + 1][x] != '1')
	{
		data->map[y][x] = '0';
		data->map[y + 1][x] = 'P';
		data->position.y = y + 1;
		rendermap(data);
	}
}
