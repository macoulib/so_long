/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:22:37 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/15 11:07:51 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <fcntl.h>  // pour O_RDONLY
#include <string.h>  // pour O_RDONLY
#include <unistd.h>    // pour read(), close()
#include <stdlib.h>    // pour malloc(), free()

#define BUFFER_SIZE 1024

typedef struct cnt_s
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}				t_cnt;

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
	char	**map;
	t_cnt	cnt;

} t_data;

void	reset_img(t_data *data);
char	*get_file_content(const char *filename);
char	**ft_split(const char *s, char c);
char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *theString );
char	**ft_split(const char *s, char c);
char	*get_next_line(int fd);
int		parsing(char *file);
int on_destroy(t_data *data);
int on_keypress(int keysym, t_data *data);

#endif