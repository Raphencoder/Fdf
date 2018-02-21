/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:45:04 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/21 22:04:21 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		ft_countnb(char *str)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	while (str[i] != '\n')
	{
		if (ft_isdigit(str[i]))
		{
			nb++;
			while (ft_isdigit(str[i]))
				i++;
		}
		else
			i++;
	}
	return (nb);
}

int		ft_all(char *str, t_check *numb, t_pos *pos)
{
	if (ft_checkgrid(str, numb, pos))
	{
		ft_putendl("Error with the map");
		return (0);
	}
	pos->tb = ft_parsing(str, pos);
	ft_strdel(&str);
	ft_graph(pos);
	return (1);
}
