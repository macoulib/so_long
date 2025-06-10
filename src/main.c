/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:46:35 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/10 17:40:35 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 80 , 80 , "macoulib :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);

    // Initialisation des images
    reset_img(&data);
	//parsing(av[1]);
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img_wall, 100, 100);
	
    // Boucle principale
    mlx_loop(data.mlx_ptr);
	return (0);
}