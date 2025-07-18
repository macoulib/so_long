/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:40:13 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/18 20:17:17 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initwindow(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, ft_strlen(data->map[0]) * 80,
			taille_tableau(data->map) * 80, "./so_long :) ");
	if (!data->win_ptr)
	{
		write(1, "erreur ouverture de fenetre ", 28);
		fkclose(data);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_data	*data;

	if (ac == 2)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			NULL;
		checkcommandeline(ac, av, data);
		get_map(data, av[1]);
		data->height = 0;
		map_valid(data);
		ft_inicnt(data);
		data->mlx_ptr = mlx_init();
		if (!data->mlx_ptr)
			ft_error("mlx_init failed", data);
		initwindow(data);
		init_images(data);
		render_data(data);
		mlx_hook(data->win_ptr, 17, 0, fkclose, data);
		mlx_key_hook(data->win_ptr, enemykey_hook, data);
		mlx_loop(data->mlx_ptr);
	}
	else
		ft_printf("nbr darg incorrect \n");
	return (0);
}
