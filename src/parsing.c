/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:13:06 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/10 13:32:34 by macoulib         ###   ########.fr       */
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
		ft_error("erreur pas de map", data);
	mapsize = ft_strlen(data->map[i]);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j != mapsize)
			ft_error("La map n'est pas cohérente,ce n'est pas un rectangle.\n",
				data);
		i++;
	}
}

void	check_content(t_data *data)
{
	int	i;
	int	j;
	int	o;

	i = 0;
	j = 0;
	o = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!ft_strchr("PE0C1T", data->map[i][j]))
				ft_error("Lettre parasite retrouver.\n", data);
			if (data->map[i][j] == '0')
				o++;
			j++;
		}
		i++;
	}
	if (o < 3)
		ft_error("pas assez de sol.\n", data);
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
		ft_error("error", data);
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
				ft_error("erreur de mur principal", data);
			j++;
		}
		if (data->map[i][0] != '1' || data->map[i][linelen - 1] != '1')
			ft_error("erreur de mur ouverte", data);
		i++;
	}
}

void	map_valid(t_data *data)
{
	int	e;
	int	c;
	int	p;

	e = 0;
	c = 0;
	p = 0;
	isrectancle(data);
	check_content(data);
	check_nbrcontent(data, e, c, p);
	check_wall(data);
}
