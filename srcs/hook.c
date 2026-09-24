/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:30:25 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/12/19 13:08:23 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	ft_putnbr(int nb)
{
	char	c;

	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}

int	press_key(int key, void *param)
{
	t_game	*program;
	int		move;
	int		x;
	int		y;

	program = (t_game *)param;
	move = 0;
	x = program->sprite_pos.x / 50;
	y = program->sprite_pos.y / 50;
	if (key == 0 && ((program->map)->file)[y][x - 1] != '1' && ++move)
		program->sprite_pos.x -= program->sprite.size.x;
	else if (key == 1 && ((program->map)->file)[y + 1][x] != '1' && ++move)
		program->sprite_pos.y += program->sprite.size.y;
	else if (key == 2 && ((program->map)->file)[y][x + 1] != '1' && ++move)
		program->sprite_pos.x += program->sprite.size.x;
	else if (key == 13 && ((program->map)->file)[y - 1][x] != '1' && ++move)
		program->sprite_pos.y -= program->sprite.size.y;
	else if (key == 53)
		ft_exit_1(program, NULL, 0);
	if (!move)
		return (0);
	change_position(program, x, y);
	return (0);
}

void	change_position(t_game *program, int x, int y)
{
	mlx_put_image_to_window(program->mlx, program->window.link,
		program->floor.link, x * 50, y * 50);
	if (((program->map)->file)[y][x] == 'C')
		(program->collects)--;
	if (((program->map)->file)[y][x] == 'E')
		mlx_put_image_to_window(program->mlx, program->window.link,
			program->exit.link, x * 50, y * 50);
	else
		((program->map)->file)[y][x] = 0;
	write(1, "move: ", 6);
	ft_putnbr(++(program->move));
	write(1, "\n", 1);
	mlx_put_image_to_window(program->mlx, program->window.link,
		program->sprite.link, program->sprite_pos.x,
		program->sprite_pos.y);
	if (((program->map)->file)[program->sprite_pos.y / 50]
		[program->sprite_pos.x / 50] == 'E' && program->collects == 0)
		ft_exit_1(program, "WIN\n", 1);
}
