/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:22:37 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/08 14:49:22 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>




typedef struct img_s
{
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}				t_img;

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
    t_img img;

} t_data;

void	reset_img(t_data *data);

#endif