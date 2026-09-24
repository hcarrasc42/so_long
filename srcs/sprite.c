/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:45:15 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/12/20 12:53:04 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	ft_sprites(t_game *program)
{
	int		y;
	int		x;

	create_image(program, &program->floor, "sprites/floor.xpm");
	create_image(program, &program->wall, "sprites/wall.xpm");
	create_image(program, &program->exit, "sprites/exit.xpm");
	create_image(program, &program->money, "sprites/collect.xpm");
	create_image(program, &program->sprite, "sprites/player.xpm");
	program->collects = 0;
	y = 0;
	while (y < (program->map)->hei)
	{
		x = 0;
		while (x < (program->map)->wid)
		{
			put_image(program, x, y);
			x++;
		}
		y++;
	}
}

void	put_image(t_game *program, int x, int y)
{
	mlx_put_image_to_window(program->mlx, program->window.link,
		program->floor.link, x * 50, y * 50);
	if ((program->map)->file[y][x] == '1')
		mlx_put_image_to_window(program->mlx, program->window.link,
			program->wall.link, x * 50, y * 50);
	if ((program->map)->file[y][x] == 'C' && ++(program->collects))
		mlx_put_image_to_window(program->mlx, program->window.link,
			program->money.link, x * 50, y * 50);
	if ((program->map)->file[y][x] == 'E')
		mlx_put_image_to_window(program->mlx, program->window.link,
			program->exit.link, x * 50, y * 50);
	if ((program->map)->file[y][x] == 'P')
	{
		program->move = 0;
		program->sprite_pos.x = x * 50;
		program->sprite_pos.y = y * 50;
		mlx_put_image_to_window(program->mlx, program->window.link,
			program->sprite.link, x * 50, y * 50);
	}
}

void	create_image(t_game *program, t_sprite *sprite, char *path)
{
	sprite->link = mlx_xpm_file_to_image(program->mlx, path,
			&sprite->size.x, &sprite->size.y);
	if (!sprite->link)
		ft_exit_1(program, "Error:\nWrong sprite", 0);
	sprite->pixels = mlx_get_data_addr(sprite->link, \
		&sprite->bits_per_pixel, &sprite->line_size, &sprite->endian);
}
