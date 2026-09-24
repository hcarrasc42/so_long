/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:30:37 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/12/19 12:28:57 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	init_game(char *argv)
{
	t_game	program;

	get_map(&program, argv);
	program.mlx = mlx_init();
	program.window.link = mlx_new_window(program.mlx,
			program.map->wid * 50, program.map->hei * 50, "so_long");
	program.window.size.x = program.map->wid * 50;
	program.window.size.y = program.map->hei * 50;
	mlx_hook(program.window.link, 17, 0, exit_game, &program);
	ft_sprites(&program);
	mlx_key_hook(program.window.link, *press_key, &program);
	mlx_loop(program.mlx);
	ft_exit_1(&program, NULL, 0);
}

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	init_game(argv[1]);
	exit(2);
	return (0);
}
