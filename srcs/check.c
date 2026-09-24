/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:04:09 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/12/22 10:15:47 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	check_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_exit_2("Error:\nInvalid argument");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_exit_2("Error:\nFile not found");
	if (ft_strcmp(argv[1], ".ber"))
		ft_exit_2("Error:\nInvalid file type, use .ber");
}
