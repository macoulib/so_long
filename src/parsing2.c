/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:33:05 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/24 20:35:19 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	isrectancle(t_data *data)
{
	int	i;
	int	j;
	int	mapsize;

	i = 0;
	j = 0;
	if (!data->map[i])
	{
		ft_error("Error\n❌ Empty map.\n", data);
	}
	mapsize = ft_strlen(data->map[i]);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j != mapsize)
			ft_error("Error\n❌ Map is not rectangular.\n", data);
		i++;
	}
}

void	check_content(t_data *data)
{
	int	i;
	int	j;
	int	o;
	int	k;

	free((i = 0, j = 0, o = 0, k = 0, NULL));
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (!ft_strchr("PE0C1T", data->map[i][j]))
				ft_error("Error\n❌Invalid map elements.\n", data);
			if (data->map[i][j] == '0')
				o++;
			else if (data->map[i][j] == 'T')
				k++;
		}
	}
	if (o < 3 || k > 1)
		ft_error("Error\n❌Invalid map elements.\n", data);
}

void	check_nbrcontent(t_data *data, int e, int c, int p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				e++;
			if (data->map[i][j] == 'C')
				c++;
			if (data->map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (c == 0 || e == 0 || p > 1 || p == 0)
	{
		ft_error("Error\n❌Missing map element\n", data);
	}
}

void	check_wall(t_data *data)
{
	int	i;
	int	j;
	int	datalen;
	int	linelen;

	i = 0;
	datalen = taille_tableau(data->map);
	linelen = ft_strlen(data->map[i]);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[0][j] != '1' || data->map[datalen - 1][j] != '1')
				ft_error("Error\n❌ Map not surrounded by walls.\n", data);
			j++;
		}
		if (data->map[i][0] != '1' || data->map[i][linelen - 1] != '1')
			ft_error("Error\n❌ Map not surrounded by walls.\n", data);
		i++;
	}
}

void	check_valid_path(t_data *data)
{
	char	**mapcpy;
	int		px;
	int		py;

	data->collectiblefound = 0;
	data->exit_found = 0;
	getplayerposition(data);
	px = data->position.x;
	py = data->position.y;
	count_collectibles(data);
	mapcpy = cpymap(data->map);
	if (!mapcpy)
		return (freemapcpy(mapcpy), (void)0);
	floodfill(mapcpy, px, py, data);
	if (!mapcpy || data->collectiblefound != data->cnt.tot_collect
		|| !data->exit_found)
	{
		freemap(data);
		freemapcpy(mapcpy);
		exit(write(2, "Error\nUnreachable element detected\n", 36));
	}
	freemapcpy(mapcpy);
}
