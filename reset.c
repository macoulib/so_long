/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:33:07 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/08 14:48:09 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



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