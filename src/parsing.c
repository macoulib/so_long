/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:13:06 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/24 20:33:31 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_valid(t_data *data)
{
	int	e;
	int	c;
	int	p;

	free((e = 0, c = 0, p = 0, NULL));
	getplayerposition(data);
	isrectancle(data);
	check_content(data);
	check_wall(data);
	check_nbrcontent(data, e, c, p);
	check_valid_path(data);
}
