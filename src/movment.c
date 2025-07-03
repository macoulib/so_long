/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:03:42 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/03 13:08:30 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rightmv(t_data *data)
{
	int	x;
	int	y;

	x = data->position.x;
	y = data->position.y;
	if (data->map[y][x  + 1] == 'T')
	{
		write(2, "perdu!", 7);
		exit(0);
	}
	if (data->map[y][x + 1] == 'E' && data->cnt.tot_collect == 0)
	{
		write(2, "gagner!", 7);
		exit(0);
		
	}
	if (data->map[y][x + 1] == 'E' && data->cnt.tot_collect > 0)
	{
		write(2, "You need to collect all collectibles to exit !", 47);
		return ;
	}
	if (data->map[y][x + 1] == 'C')
			data->cnt.tot_collect--;
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
	if (data->map[y][x - 1] == 'T')
	{
		write(2, "perdu! ", 7);
		exit(0);
	}
	if (data->map[y][x - 1] == 'E' && data->cnt.tot_collect == 0)
	{
		write(2, "gagner!", 7);
		exit(0);
	}
	if (data->map[y][x - 1] == 'E' && data->cnt.tot_collect > 0)
	{
		write(2, "You need to collect all collectibles to exit !", 47);
		return ;
	}
		if (data->map[y][x - 1] == 'C')
			data->cnt.tot_collect--;
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
	if (data->map[y - 1][x] == 'T')
	{
		write(2, "perdu!", 7);
		exit(0);
	}
	if (data->map[y - 1][x] == 'E' && data->cnt.tot_collect == 0)
	{
		write(2, "gagner!", 7);
		exit(0);
	}
	if (data->map[y - 1][x] == 'E' && data->cnt.tot_collect > 0)
	{
		write(2, "You need to collect all collectibles to exit !", 47);
		return ;
	}
	if (data->map[y - 1][x] == 'C')
			data->cnt.tot_collect--;
	if (y - 1 >= 0 && data->map[y - 1][x] != '1')
	
	{ 	data->map[y][x] = '0';
		data->map[y - 1][x] = 'P';
		data->position.y = y - 1;
		rendermap(data);}
}

void	downmv(t_data *data)
{
	int	x;
	int	y;

	x = data->position.x;
	y = data->position.y;
	
	if (data->map[y + 1][x] == 'T')
	{
		write(2, "perdu!", 7);
		exit(0);
	}
	if (data->map[y + 1][x] == 'E' && data->cnt.tot_collect == 0)
	{
		write(2, "gagner!", 7);
		exit(0);
	}
	if (data->map[y + 1][x] == 'E' && data->cnt.tot_collect > 0)
	{
		write(2, "You need to collect all collectibles to exit !", 47);
		return ;
	}
	if (data->map[y + 1 ][x] == 'C')
			data->cnt.tot_collect--;
	if (data->map[y + 1] && data->map[y + 1][x] != '1')
	{
		data->map[y][x] = '0';
		data->map[y + 1][x] = 'P';
		data->position.y = y + 1;
		rendermap(data);
	}
}
