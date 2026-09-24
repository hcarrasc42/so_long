/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:09:23 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/12/19 11:32:01 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	j;
	int	len;

	j = 0;
	if (!s1)
		return (0);
	len = ft_strlen(s1) - 1;
	while (len >= 0)
	{
		if (s1[len] == '.')
			break ;
		len--;
	}
	if (s1[len] != '.')
		return (0);
	while (s2[j])
	{
		if (s1[len] != s2[j])
			return (1);
		len++;
		j++;
	}
	return (0);
}
