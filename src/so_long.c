/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:40:13 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/24 21:06:44 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac , char *av[])
{
    t_data  *data;
    data = malloc(sizeof(t_data));
    checkcommandeline(ac,av);
    get_map(data,av[1]);
    map_valid(data);
    ft_inicnt(data);
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window( data->mlx_ptr,ft_strlen(data->map[0]) * 80, taille_tableau(data->map) * 80,"macoulib :) ");
    if (!data->win_ptr)
    {   
        free(data->win_ptr);
        ft_error("error");   
    }
    render_data(data);
    mlx_loop(data->mlx_ptr);

    return (0);
}