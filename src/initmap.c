/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:56:58 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/24 14:26:25 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include  "so_long.h"


void checkcommandeline(int ac , char *av[])
{
    int avleng;

    if (ac > 2)
        ft_error("erreur argument nombreux");
    if (ac < 2)
        ft_error("erreur manque d' argument");
    avleng = ft_strlen(av[1]);
    if (avleng < 4) 
        ft_error("erreur d'extension");
    if (!ft_strnstr(&av[1][avleng - 4], ".ber", 4))
        ft_error("erreur d'extension");
}

char	*freestats(char	*staticbuffer, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(staticbuffer, buffer);
	free(staticbuffer);
	return (temp);
}

void get_map(t_data *data , char *av)
{
    int fd;
    char *linestock;
    char *line;

    fd = open(av, O_RDONLY);
    if(fd == - 1)
           ft_error("erreur d'ouverture du fd ");
    linestock = ft_strdup("");
    data->height = 0 ;
    while ((line = get_next_line(fd)) != NULL)
    {
       linestock = freestats(linestock, line);
       if (!linestock)
       {
            free(line);
            break;
       }
       data->height ++;
       free(line);
    }
    close (fd);   
    data->map = ft_split(linestock, '\n');
    free(linestock);
}

 
