/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:32:37 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/30 21:54:28 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

void ft_inicnt(t_data *data)
{

    int x = 12;
    int y = 12;
    
    data->cnt.coins = 0;
    data -> cnt.exit = 0;
    data->cnt.player =0;
    data->position.x = 0;
    data->position.y = 0;

    data->img.wall= mlx_xpm_file_to_image(data->mlx_ptr, "./ressources/xpm/wall_texture.xpm", &x, &y);
    data->img.floor = mlx_xpm_file_to_image(data->mlx_ptr, "./ressources/xpm/floor_texture.xpm", &x, &y);
    data->img.exit = mlx_xpm_file_to_image(data->mlx_ptr, "./ressources/xpm/exit_texture.xpm", &x, &y);
    data->img.collectible = mlx_xpm_file_to_image(data->mlx_ptr, "./ressources/xpm/collectible_texture.xpm", &x, &y);
    data->img.player = mlx_xpm_file_to_image(data->mlx_ptr, "./ressources/xpm/mario_player.xpm", &x, &y);
}