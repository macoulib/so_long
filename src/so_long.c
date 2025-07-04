/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:40:13 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/04 16:20:13 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	main(int ac, char *av[])
{
	t_data *data;
	data = malloc(sizeof(t_data));
	checkcommandeline(ac, av);
	get_map(data, av[1]);
	map_valid(data);
	ft_inicnt(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_error("mlx_init failed");
	data->win_ptr = mlx_new_window(data->mlx_ptr, ft_strlen(data->map[0]) * 80,
			taille_tableau(data->map) * 80, "./so_long :) ");
	if (!data->win_ptr)
		ft_error("error");
	init_images(data);
	render_data(data);
	mlx_hook(data->win_ptr, 17, 0, close_window, NULL);
	mlx_key_hook(data->win_ptr, enemykey_hook, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}