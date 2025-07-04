/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:22:37 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/04 16:42:35 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFEressources
#  define BUFFER_SIZE 1024
# endif

# define IMGHEIGHT 32
# define IMGWIDTH 32
# define ESC_KEY 53
# define TILE_SIZE 32

typedef struct position_s
{
	int			x;
	int			y;
}				t_positon;

typedef struct eposition_s
{
	int			x;
	int			y;
}				t_epositon;

typedef struct s_img
{
	void		*collectible;
	void		*wall;
	void		*exit;
	void		*player;
	void		*player1;
	void		*floor;
	void		*enemy;
}				t_img;

typedef struct cnt_s
{
	int			coins;
	int			exit;
	int			player;
	int			mvt;
	int			tot_collect;
}				t_cnt;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	char		**map;
	void		*player_img;
	t_img		img;
	t_cnt		cnt;
	t_positon	position;
	t_epositon	eposition;

}				t_data;

void			ft_error(const char *message);
char			*ft_strnstr(const char *big, const char *little, size_t len);
void			checkcommandeline(int ac, char *av[]);
size_t			ft_strlen(const char *theString);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *src);
char			**ft_split(const char *s, char c);
char			*ft_strchr(const char *s, int c);
void			ft_inicnt(t_data *data);
char			*get_next_line(int fd);
void			get_map(t_data *data, char *av);
void			map_valid(t_data *data);
int				taille_tableau(char **tab);
void			ft_inicnt(t_data *data);
void			render_data(t_data *data);
int				fkclose(t_data *data);
int				key_hook(int keycode, t_data *data);
void			rightmv(t_data *data);
void			leftmv(t_data *data);
void			upmv(t_data *data);
void			downmv(t_data *data);
void			rightmvt(t_data *data);
void			leftmvt(t_data *data);
void			upmvt(t_data *data);
void			downmvt(t_data *data);
void			init_images(t_data *data);
void			rendermap(t_data *data);
void			init_images(t_data *data);
void			displayimg(t_data *data, int y, int x);
char			*ft_itoa(int n);
int				enemykey_hook(int keycode, t_data *data);
void			forleft(t_data *data, int x, int y);
void			foright(t_data *data, int x, int y);
void			fordown(t_data *data, int x, int y);
void			fordown(t_data *data, int x, int y);

#endif