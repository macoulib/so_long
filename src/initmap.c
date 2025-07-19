/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:56:58 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/19 19:07:24 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkcommandeline(int ac, char *av[], t_data *data)
{
	int	avleng;

	checkxpm(data);
	if (ac > 2)
		ft_error("❌ Erreur : nombre d’arguments incorrect.", data);
	if (ac < 2)
		ft_error("❌ Erreur : nombre d’arguments incorrect.", data);
	avleng = ft_strlen(av[1]);
	if (avleng < 4)
	{
		ft_printf("❌ Erreur : l’extension du fichier n’est pas prise en chargen ");
		free(data);
		exit(0);
	}
	if (!ft_strnstr(&av[1][avleng - 4], ".ber", 4))
	{
		ft_printf("❌ Erreur : l’extension du fichier n’est pas prise en charge faut .ber");
		free(data);
		exit(0);
	}
}

char	*freestats(char *staticbuffer, char *buffer, t_data *data)
{
	char	*temp;

	if (ft_strlen(buffer) <= 1)
	{
		free(data);
		free(staticbuffer);
		free(buffer);
		write(2, "erreur dans la map \n", 20);
		exit(0);
	}
	temp = ft_strjoin(staticbuffer, buffer);
	free(staticbuffer);
	return (temp);
}

void	get_map(t_data *data, char *av)
{
	int		fd;
	char	*linestock;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error("❌ erreur d'ouverture du fd ", data);
	linestock = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		linestock = freestats(linestock, line, data);
		if (!linestock)
		{
			free(line);
			break ;
		}
		data->height++;
		free(line);
	}
	close(fd);
	data->map = ft_split(linestock, '\n');
	free(linestock);
}
