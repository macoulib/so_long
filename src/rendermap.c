/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:09:26 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/30 21:49:37 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"


void img_forposition(t_data *data, int i , int j)
{
    int x = 12;
    int y = 12;
    char dataimg;
    
    dataimg = data->map[i][j];
    if(dataimg == '1')
        mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,data->img.wall, j * x   ,i  * y);
    else if(dataimg == '0')
              mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,data->img.floor, j * x  ,i * y);
    else if(dataimg == 'E')
             mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,data->img.exit, j * x  ,i * y);
   else  if(dataimg == 'C')
           mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,data->img.collectible, j * x ,i * y);
   else if(dataimg == 'P')
            mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,data->img.player, j * x ,i * y);
}


void render_data(t_data *data)
{
    int i;
    int j;
    
    i = 0;
    while (taille_tableau(data->map)  > i)
    {
            j = 0; 
            while (ft_strlen(data->map[0])  > j)
            {
                img_forposition(data,i,j);
                j++;
            }
            i++;
    }
}