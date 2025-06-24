/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:09:26 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/24 21:12:08 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"


void img_forposition(t_data *data, int i , int j)
{
    int x = 32;
    int y = 32;
    char dataimg;
    void *img = mlx_xpm_file_to_image(data->mlx_ptr, "./ressources/xpm/wall_texture.xpm", &x, &y);
    void *img1 = mlx_xpm_file_to_image(data->mlx_ptr, "./ressources/xpm/exit_texture.xpm", &x, &y);
    void *img2 = mlx_xpm_file_to_image(data->mlx_ptr, "./ressources/xpm/floor_texture.xpm", &x, &y);
    void *img3 = mlx_xpm_file_to_image(data->mlx_ptr, "./ressources/xpm/collectible_texture.xpm", &x, &y);
    void *img4 = mlx_xpm_file_to_image(data->mlx_ptr, "./ressources/xpm/mario_player.xpm", &x, &y);
    void *img5 = mlx_xpm_file_to_image(data->mlx_ptr, "./ressources/xpm/perso_texture.xpm", &x, &y);
    void *img6 = mlx_xpm_file_to_image(data->mlx_ptr, "./ressources/xpm/collect.xpm", &x, &y);

    dataimg = data->map[i][j];
    if(dataimg == '1')
        mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,img, j * x   ,i  * y);
    else if(dataimg == '0')
              mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,img2, j * x  ,i * y);
    else if(dataimg == 'E')
             mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,img1, j * x  ,i * y);
   else  if(dataimg == 'C')
           mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,img4, j * x ,i * y);
   else if(dataimg == 'P')
            mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,img5, j * x ,i * y);
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