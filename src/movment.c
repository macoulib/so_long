/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:03:42 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/30 21:34:10 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

void rightmv(t_data *data)
{
    int x;
    int y;

    x = data->position.x;
    y = data->position.y;

    if ( y > 0 && (data->map[y][x + 1] != '1'))
    {
        data->map[y][x + 1] = 'E';
        data->map[y ][x] = '0';
        data->position.x = x + 1;
    }
}
void leftmv(t_data *data)
{
    int x;
    int y;

    x = data->position.x;
    y = data->position.y;

    if ( y > 0 && (data->map[y][x - 1] != '1'))
    {
        data->map[y][x - 1] = '1';
        data->map[y][x] = '0';
        data->position.x = x - 1;
    }

}

void upmv(t_data *data)
{
    int x;
    int y;

    x = data->position.x;
    y = data->position.y;

    if ( y > 0 && (data->map[y + 1][x] != '1'))
    {
        data->map[y + 1][x] = 'E';
        data->map[y ][x] = '0';
        data->position.y = y + 1;
    }

    
}


void downmv(t_data *data)
{
    int x;
    int y;

    x = data->position.x;
    y = data->position.y;

    if ( y > 0 && (data->map[y - 1][x] != '1'))
    {
        data->map[y - 1][x] = 'E';
        data->map[y ][x] = '0';
        data->position.y = y - 1;
    }
    
}
