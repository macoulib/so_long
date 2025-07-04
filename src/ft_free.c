/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:00:34 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/04 18:33:48 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap(t_data *data)
{
	int	i;

	i = 1;
	if (data->map[0])
	{
			free(data);
			return ;
	}
		
	while (data->map[i - 1])
	{
		free(data->map[i]);
		i++;
	}
}

void	destroy_images(t_data *data)
{
	if (data->img.wall)
		mlx_destroy_image(data->mlx_ptr, data->img.wall);
	if (data->img.floor)
		mlx_destroy_image(data->mlx_ptr, data->img.floor);
	if (data->img.exit)
		mlx_destroy_image(data->mlx_ptr, data->img.exit);
	if (data->img.collectible)
		mlx_destroy_image(data->mlx_ptr, data->img.collectible);
	if (data->img.enemy)
		mlx_destroy_image(data->mlx_ptr, data->img.enemy);
	if (data->player_img)
		mlx_destroy_image(data->mlx_ptr, data->player_img);
    
}
