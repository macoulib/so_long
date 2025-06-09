/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:46:35 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/09 23:36:44 by macoulib         ###   ########.fr       */
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
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 400, "macoulib :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);


    // Initialisation des images
    reset_img(&data);

   data.map = load_map("map.ber");
   if (!data.map)
{
    write(2, "Erreur: map non chargée\n", 25);
    return (1);
}

// Debug : Afficher la map dans le terminal
for (int i = 0; data.map[i]; i++)
    printf("%s\n", data.map[i]);

   draw_map(&data);
	
    // Boucle principale
    mlx_loop(data.mlx_ptr);
	return (0);
}