/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:45:04 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/01 16:15:59 by rkrief           ###   ########.fr       */
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

void    ft_all(char *str, s_check *numb)
{
	int **tab;

	if (!ft_checkgrid(str, numb))
	{
		ft_putendl("Error with the map");
		return ;
	}
	numb->nbl = ft_countnb(str);
	if (numb->nbl * numb->fline != numb->nb)
	{
		ft_putendl("Error with the map");
		return ;
	}
	tab = ft_parsing(str, numb);
	int i;
	int j;

	i = 0;
	j = 0;
	while(tab[i])
	{
		while(tab[i][j])
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
