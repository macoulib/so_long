/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:55:57 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/24 19:01:26 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemapcpy(char **mapcpy)
{
	int	i;

	i = 0;
	while (mapcpy[i])
	{
		free(mapcpy[i]);
		i++;
	}
	free(mapcpy);
}

char	**cpymap(char **map)
{
	int		y;
	char	**cpymap;

	y = 0;
	while (map[y])
		y++;
	cpymap = malloc((y + 1) * sizeof(char *));
	if (!cpymap)
		return (NULL);
	y = 0;
	while (map[y])
	{
		cpymap[y] = ft_strdup(map[y]);
		if (!cpymap[y])
		{
			freemapcpy(cpymap);
			return (NULL);
		}
		y++;
	}
	cpymap[y] = NULL;
	return (cpymap);
}

void	getplayerposition(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->position.x = x;
				data->position.y = y;
			}
			x++;
		}
		y++;
	}
}

void	floodfill(char **map, int x, int y, t_data *data)
{
	if (!map || y < 0 || x < 0 || !map[y] || map[y][x] == '\0')
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'T')
		return ;
	if (map[y][x] == 'E')
	{
		data->exit_found = 1;
		return ;
	}
	if (map[y][x] == 'C')
		data->collectiblefound++;
	map[y][x] = 'V';
	floodfill(map, x + 1, y, data);
	floodfill(map, x - 1, y, data);
	floodfill(map, x, y + 1, data);
	floodfill(map, x, y - 1, data);
}
