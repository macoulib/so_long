/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:33:56 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/04 16:44:58 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	foright(t_data *data, int x, int y)
{
	if (data->map[y][x + 1] == 'T')
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
}

void	forleft(t_data *data, int x, int y)
{
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
}

void	forup(t_data *data, int x, int y)
{
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
}

void	fordown(t_data *data, int x, int y)
{
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
	if (data->map[y + 1][x] == 'C')
		data->cnt.tot_collect--;
}