/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:38:41 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/03 19:25:10 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fkclose(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}



int	key_hook(int keycode, t_data *data)
{
	int i = 0;

	
	if (keycode == 65307)
	{
		fkclose(data);
	} // ESC

	else if (keycode == 97)
	{
		leftmv(data);
		data->cnt.mvt++;int enemy_dir;

	}

	else if (keycode == 100)
	{
		rightmv(data);
		data->cnt.mvt++;
	} // 'd'

	else if (keycode == 119)
	{
		upmv(data);
		data->cnt.mvt++;
	} // 'w'

	else if (keycode == 115)
	{
		downmv(data);
		data->cnt.mvt++;
	} // 's'

	return (0);
}