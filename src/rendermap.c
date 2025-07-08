/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:09:26 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/08 17:33:19 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_data *data)
{
	int	width;
	int	height;

	data->img.wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./ressources/xpm/wall_texture.xpm", &width, &height);
	data->img.floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"./ressources/xpm/floor_texture.xpm", &width, &height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"./ressources/xpm/exit_texture.xpm", &width, &height);
	data->img.collectible = mlx_xpm_file_to_image(data->mlx_ptr,
			"./ressources/xpm/collect.xpm", &width, &height);
	data->img.player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./ressources/xpm/mario_player.xpm", &width, &height);
	data->img.enemy = mlx_xpm_file_to_image(data->mlx_ptr,
			"./ressources/xpm/perso_texture.xpm", &width, &height);
	data->img.player1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./ressources/xpm/mario_player1.xpm", &width, &height);
}

void	rendermap(t_data *data)
{
	int		x;
	int		y;
	char	*str;
	char	*msg;

	y = 0;
	while (data->map[y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			displayimg(data, y, x);
		}
		y++;
	}
	str = ft_itoa(data->cnt.mvt);
	msg = ft_strjoin("Mouvements : ", str);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 40, 20, 0xFFFFFF, msg);
	free(str);
	free(msg);
}

void	displayimg(t_data *data, int y, int x)
{
	int	tile_size;

	tile_size = 80;
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.wall, x
			* tile_size, y * tile_size);
	else if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.floor, x
			* tile_size, y * tile_size);
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.exit, x
			* tile_size, y * tile_size);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.collectible, x * tile_size, y * tile_size);
	else if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img,
			x * tile_size, y * tile_size);
	else if (data->map[y][x] == 'T')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.enemy, x
			* tile_size, y * tile_size);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.collectible, x * tile_size, y * tile_size);
}

void	render_data(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->player_img = data->img.player;
	while (taille_tableau(data->map) > i)
	{
		data->player_img = data->img.player;
		j = 0;
		while (ft_strlen(data->map[0]) > j)
		{
			rendermap(data);
			j++;
		}
		i++;
	}

}
