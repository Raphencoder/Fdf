/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:45:04 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/05 13:33:38 by rkrief           ###   ########.fr       */
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

	if (ft_checkgrid(str, numb))
	{
		ft_putendl("iError with the map");
		return ;
	}
	tab = ft_parsing(str, numb);
	ft_graph(tab, numb);
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < numb->line)
	{
		while(j < numb->nbl)
		{
			ft_putnbr(tab[i][j]);
			if (tab[i][j] >= 0 && tab[i][j] <= 9)
			{
				ft_putchar(' ');
				ft_putchar(' ');
			}
			else
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
	return ;
}
