/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:18:59 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/12/20 13:39:41 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>

# include "colors.h"
# include "../minilibx/mlx.h"
# include "../srcs/get_next_line/get_next_line.h"

typedef struct s_map
{
	char		**file;
	int			wid;
	int			hei;
}				t_map;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_wind
{
	void		*link;
	t_pos		size;
}				t_wind;

typedef struct s_sprite
{
	void		*link;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
	t_pos		size;
}				t_sprite;

typedef struct s_game
{
	void		*mlx;
	t_map		*map;
	t_wind		window;
	t_sprite	wall;
	t_sprite	floor;
	t_sprite	money;
	t_sprite	exit;
	t_sprite	sprite;
	t_pos		sprite_pos;
	int			move;
	int			collects;
	int			pl;
	int			ex;
	int			he;
}				t_game;

// Check
void				check_args(int argc, char **argv);

//sprites
void				ft_sprites(t_game *program);
void				create_image(t_game *program, t_sprite *sprite, char *path);
void				put_image(t_game *program, int x, int y);

// Utils
void				ft_exit_2(char *str);
void				free_map(t_map **map);
void				printerror(char *msg);
void				ft_exit_1(t_game *program, char *str, int i);

// Map
void				get_map(t_game *program, char *argv);

// Libft
int					ft_strcmp(char *s1, char *s2);
char				**ft_split(char *s, char c);
void				*ft_memset(void *b, int c, size_t len);

// Hook
int					press_key(int key, void *param);
void				change_position(t_game *program, int x, int y);

int					exit_game(void *param);

#endif
