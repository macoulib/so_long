/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:33:07 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/09 23:11:10 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	set_content(t_cnt *content)
{
	content->exit = 'E';
	content->player = 'P';
	content->wall = '1';
	content->space = '0';
	content->collect = 'C';
	content->count_p = 0;
	content->count_e = 0;
	content->count_c = 0;
}

void	reset_img(t_data *data)
{
	data->img.height = 80;
	data->img.width = 80;
	data->img.floor = "./ressources/floor_texture.xpm";
	data->img.wall = "./ressources/wall_texture.xpm";
	data->img.collect = "./ressources/collect.xpm";
	data->img.player = "./ressources/mario_player.xpm";
	data->img.exit = "./ressources/exit_texture.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
			&(data->img.width), &(data->img.height));
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, data->img.floor,
			&(data->img.width), &(data->img.height));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
			&(data->img.width), &(data->img.height));
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collect, &(data->img.width), &(data->img.height));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;
	char	tile;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			tile = data->map[y][x];
			if (tile == data->cnt.wall)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img.img_wall, x * data->img.width, y * data->img.height);
			else if (tile == data->cnt.space)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img.img_floor, x * data->img.width, y * data->img.height);
			else if (tile == data->cnt.player)
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img.img_floor, x * data->img.width, y * data->img.height);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img.img_player, x * data->img.width, y * data->img.height);
			}
			else if (tile == data->cnt.collect)
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img.img_floor, x * data->img.width, y * data->img.height);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img.img_collect, x * data->img.width, y * data->img.height);
			}
			else if (tile == data->cnt.exit)
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img.img_floor, x * data->img.width, y * data->img.height);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img.img_exit, x * data->img.width, y * data->img.height);
			}
			x++;
		}
		y++;
	}
}
