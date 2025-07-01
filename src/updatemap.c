/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatemap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:04:22 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/29 01:01:04 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include  "so_long.h"

int	ftclose(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	//ft_free_array(map->array, map->y);
	exit(EXIT_SUCCESS);
	return (0);
}