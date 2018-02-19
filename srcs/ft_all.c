/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:45:04 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/19 18:38:59 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int     ft_countnb(char *str)
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

void    ft_all(char *str, s_check *numb, s_pos *pos)
{

	if (ft_checkgrid(str, numb, pos))
	{
		ft_putendl("iError with the map");
		return ;
	}
	pos->tab = ft_parsing(str, pos);
	ft_graph(pos);
	return ;
}
