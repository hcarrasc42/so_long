/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:13:56 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/12/20 14:12:52 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	ft_error(t_game *program, int nb, char *map_str)
{
	if (!map_str)
	{
		free(map_str);
		ft_exit_1(program, "Error:\nWrong map", 0);
	}
	else if (nb == 3)
	{
		if (program->pl != 1)
			ft_exit_1(program, "Error:\nWrong player", 0);
		if (program->ex != 1)
			ft_exit_1(program, "Error:\nWrong exit", 0);
		if (program->he < 3)
			ft_exit_1(program, "Error:\nWrong height", 0);
	}
	else
		return ;
}

int	check_content(t_game *program, char *row, int pos_row)
{
	int		i;

	i = 0;
	(program->map)->wid = ft_strlen((program->map)->file[0]);
	while (row[i])
	{
		if (row[i] != '1' && row[i] != '0' && row[i] != 'P'
			&& row[i] != 'C' && row[i] != 'E')
			ft_exit_1(program, "Error:\nWrong char", 0);
		if ((pos_row == 0 || pos_row == 2) && row[i] != '1')
			return (1);
		else if ((i == 0 || i == (program->map)->wid - 1) && row[i] != '1')
			ft_exit_1(program, "Error:\nWrong map", 0);
		if (row[i] == 'P')
			program->pl += 1;
		if (row[i] == 'E')
			program->ex += 1;
		i++;
	}
	if (i != (program->map)->wid)
		ft_exit_1(program, "Error:\nWrong width", 0);
	return (0);
}

int	check_map(t_game *program)
{
	int		pos_row;
	char	**map_str;

	map_str = (program->map)->file;
	program->he = 0;
	program->pl = 0;
	program->ex = 0;
	while (map_str[program->he])
	{
		if (program->he == 0)
			pos_row = 0;
		else if (map_str[program->he + 1])
			pos_row = 1;
		else
			pos_row = 2;
		if (check_content(program, map_str[program->he], pos_row))
			return (1);
		program->he++;
	}
	if (program->he < 3 || program->pl != 1 || program->ex != 1)
		return (3);
	(program->map)->hei = program->he;
	return (0);
}

void	get_map(t_game *program, char *file)
{
	char	*map_str;
	char	*line;
	int		fd;

	program->map = ft_calloc(1, sizeof(t_map));
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	map_str = NULL;
	map_str = ft_strjoin(line, "");
	line = get_next_line(fd);
	while (line)
	{
		map_str = ft_strjoin(map_str, line);
		free (line);
		line = get_next_line(fd);
	}
	(program->map)->file = ft_split(map_str, '\n');
	ft_error(program, check_map(program), map_str);
	free (map_str);
}
