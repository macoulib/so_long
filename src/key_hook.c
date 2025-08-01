/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:38:41 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/24 20:57:35 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fkclose(t_data *data)
{
	destroy_images(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	freemap(data);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		fkclose(data);
	else if (keycode == 97)
	{
		leftmv(data);
		ft_printf("Mouvments : %d \n", data->cnt.mvt++);
	}
	else if (keycode == 100)
	{
		rightmv(data);
		ft_printf("Mouvments : %d \n", data->cnt.mvt++);
	}
	else if (keycode == 119)
	{
		upmv(data);
		ft_printf("Mouvments : %d \n", data->cnt.mvt++);
	}
	else if (keycode == 115)
	{
		downmv(data);
		ft_printf("Mouvments : %d \n", data->cnt.mvt++);
	}
	return (0);
}

int	enemykey_hook(int keycode, t_data *data)
{
	key_hook(keycode, data);
	if (init_enemy(data))
	{
		if (keycode == 65362)
			upmvt(data);
		else if (keycode == 65361)
			leftmvt(data);
		else if (keycode == 65363)
			rightmvt(data);
		else if (keycode == 65364)
			downmvt(data);
	}
	return (0);
}
