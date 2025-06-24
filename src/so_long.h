/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:22:37 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/24 20:07:14 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <fcntl.h>  
#include <string.h>  
#include <unistd.h>    
#include <stdlib.h>    


# ifndef BUFFEressources
#  define BUFFER_SIZE 1024
# endif

# define IMGHEIGHT			32
# define IMGWIDTH			32

typedef struct position_s
{
	int	x;
	int	y;
}	t_positon;



typedef struct img_s
{
	void	*xpm_ptr;
	int		x;
	int		y;
} t_img;


typedef struct cnt_s
{
	int	rows;
	int	columns;
	int	coins;
	int	exit;
	int	player;
}				t_cnt;

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	int		width;
	int		height;
	char	**map;
    t_img	img;

	t_cnt	cnt;
}  t_data;

void ft_error(const char *message);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void checkcommandeline(int ac , char *av[]);
size_t	ft_strlen( const char *theString );
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
void ft_inicnt(t_data *data);
char	*get_next_line(int fd);
void get_map(t_data *data , char *av);
void map_valid(t_data *data);
int taille_tableau(char **tab);
void ft_inicnt(t_data *data);
void img_forposition(t_data *data, int i , int j);
void render_data(t_data *data);

#endif