/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:02:19 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/12/20 13:23:55 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"

int	ft_len_c(char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 1;
	if (!str)
		ft_exit_2("Empty file");
	while (str[i])
	{
		if (str[i] == c)
			len++;
		i++;
	}
	return (len);
}

int	ft_len_word(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i])
	{
		while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			return (len);
		len++;
		i++;
	}
	return (len);
}

int	jump_spaces(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i] && str[i] == '\n')
	{
		j++;
		i++;
	}
	if (j > 1)
		ft_exit_2("Error:\nWrong space");
	while (str[i] && (str[i] == '\n' || str[i] == '\t' || str[i] == ' '))
		i++;
	return (i);
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		k;
	int		j;
	char	**tmp;

	i = ft_len_c(str, c);
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		i = jump_spaces(str, i);
		tmp[k] = ft_calloc((ft_len_word(str, i) + 1), sizeof(char));
		while (str[i] && str[i] != '\n' && str[i] != '\t' && str[i] != ' ')
		{
			tmp[k][j] = str[i];
			i++;
			j++;
		}
		tmp[k][j] = '\0';
		k++;
	}
	tmp[k] = NULL;
	return (tmp);
}
