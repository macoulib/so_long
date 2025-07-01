/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:38:41 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/30 21:37:00 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include  "so_long.h"



int fkclose( t_data *data)
{

        mlx_destroy_window(data->mlx_ptr, data->win_ptr);

    return (0);
}


int	key_hook(int keycode, t_data *data)
{
	
	printf("keycode = %d\n", keycode);
	if (keycode == 65307) // ESC
		fkclose(data);
	else if (keycode == 113) // 'a'
		leftmv(data);
	else if (keycode == 119) // 'd'
		rightmv(data);
	else if (keycode == 101) // 'w'
		upmv(data);
	else if (keycode == 114) // 's'
		downmv(data);
	return (0);
}