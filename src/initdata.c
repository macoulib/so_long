/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:32:37 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/24 20:09:33 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

void ft_inicnt(t_data *data)
{
    data->cnt.coins = 0;
    data -> cnt.exit = 0;
    data->cnt.player =0;
    data->img.x = 0;
    data->img.y = 0;
}