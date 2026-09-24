/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:45:00 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/12/20 12:53:57 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	exit_game(void *param)
{
	t_game	*program;

	program = (t_game *)param;
	free_map(&program->map);
	exit(0);
}

void	ft_exit_2(char *str)
{
	if (str != NULL)
		printerror(str);
	exit (2);
}

void	ft_exit_1(t_game *program, char *str, int nb)
{
	int	i;

	i = 0;
	free_map(&program->map);
	if (str == NULL)
		exit(2);
	if (nb == 1)
	{
		while (str[i])
			i++;
		write(1, GREEN, 7);
		write(1, str, i);
	}
	else
		printerror(str);
	exit (2);
}

void	free_map(t_map **map)
{
	int	i;

	i = 0;
	while ((*map)->file[i])
	{
		free((*map)->file[i]);
		i++;
	}
	free((*map)->file);
	free(*map);
}

void	printerror(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
		i++;
	write(1, RED, 8);
	write(2, msg, i);
	write(1, "\n", 1);
}
