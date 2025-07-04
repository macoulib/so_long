/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemymovment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:49:58 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/04 20:36:08 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rightmvt(t_data *data)
{
	int	x;
	int	y;

	x = data->eposition.x;
	y = data->eposition.y;
	if (data->map[y][x + 1] == 'P')
	{
		write(2, "perdu!", 7);
		fkclose(data);
	}
	if (data->map[y][x + 1] != '1' && data->map[y][x + 1] != '\0'
		&& data->map[y][x + 1] != 'C')
	{
		data->map[y][x] = '0';
		data->map[y][x + 1] = 'T';
		data->eposition.x = x + 1;
		rendermap(data);
	}
}

void	leftmvt(t_data *data)
{
	int	x;
	int	y;

	x = data->eposition.x;
	y = data->eposition.y;
	if (data->map[y][x - 1] == 'P')
	{
		write(2, "perdu! ", 7);
		fkclose(data);
	}
	if (x - 1 >= 0 && data->map[y][x - 1] != '1' && data->map[y][x - 1] != 'C')
	{
		data->map[y][x] = '0';
		data->map[y][x - 1] = 'T';
		data->eposition.x = x - 1;
		rendermap(data);
	}
}

void	upmvt(t_data *data)
{
	int	x;
	int	y;

	x = data->eposition.x;
	y = data->eposition.y;
	if (data->map[y - 1][x] == 'P')
	{
		write(2, "perdu!", 7);
		fkclose(data);
	}
	if (y - 1 >= 0 && data->map[y - 1][x] != '1' && data->map[y - 1][x] != 'C')
	{
		data->map[y][x] = '0';
		data->map[y - 1][x] = 'T';
		data->eposition.y = y - 1;
		rendermap(data);
	}
}

void	downmvt(t_data *data)
{
	int	x;
	int	y;

	x = data->eposition.x;
	y = data->eposition.y;
	if (data->map[y + 1][x] == 'P')
	{
		write(2, "perdu!", 7);
		fkclose(data);
	}
	if (data->map[y + 1] && data->map[y + 1][x] != '1' && data->map[y
		+ 1][x] != 'C')
	{
		data->map[y][x] = '0';
		data->map[y + 1][x] = 'T';
		data->eposition.y = y + 1;
		rendermap(data);
	}
}
