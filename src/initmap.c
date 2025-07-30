/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:56:58 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/24 20:26:30 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkcommandeline(char *av[], t_data *data)
{
	int	avleng;

	avleng = ft_strlen(av[1]);
	if (avleng < 4)
	{
		ft_printf("Error\n❌ Invalid file extension.\n");
		free(data);
		exit(0);
	}
	if (!ft_strnstr(&av[1][avleng - 4], ".ber", 4))
	{
		ft_printf("Error\n❌ You must input a .ber file.\n");
		free(data);
		exit(0);
	}
}

char	*freestats(char *staticbuffer, char *buffer, t_data *data, int fd)
{
	char	*temp;

	if (ft_strlen(buffer) <= 1)
	{
		free(data);
		free(staticbuffer);
		free(buffer);
		temp = get_next_line(-1);
		if (fd > 2)
			close(fd);
		write(2, "Error\n❌ Empty line detected in map.\n", 37);
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
		echecouverturedufichier(data);
	linestock = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		linestock = freestats(linestock, line, data, fd);
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
