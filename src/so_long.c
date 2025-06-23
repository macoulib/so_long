/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:40:13 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/23 19:05:16 by macoulib         ###   ########.fr       */
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
    //init_cnt(data);
    data->mlx_ptr = mlx_init();
    
    data->win_ptr = mlx_new_window( data->mlx_ptr, 600,200, "macoulib :) ");
    if (!data->win_ptr)
    {
        printf("Window creation failed\n");
        return (free(data->win_ptr), 1);    
    }
    mlx_loop(data->mlx_ptr);

    return (0);
}