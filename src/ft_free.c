/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:00:34 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/20 22:00:50 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data);
}

void	destroy_images(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.wall);
	mlx_destroy_image(data->mlx_ptr, data->img.floor);
	mlx_destroy_image(data->mlx_ptr, data->img.exit);
	mlx_destroy_image(data->mlx_ptr, data->img.collectible);
	mlx_destroy_image(data->mlx_ptr, data->img.enemy);
	mlx_destroy_image(data->mlx_ptr, data->img.player);
	mlx_destroy_image(data->mlx_ptr, data->img.player1);
}

void	destroyeur(t_data *data)
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
	if (data->img.player)
		mlx_destroy_image(data->mlx_ptr, data->img.player);
	if (data->img.player1)
		mlx_destroy_image(data->mlx_ptr, data->img.player1);
}

void	echecouverturedufichier(t_data *data)
{
	ft_printf("echec d'ouverture du fichier");
	free(data);
	exit(0);
}
