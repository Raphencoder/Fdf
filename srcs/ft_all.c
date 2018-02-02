/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:45:04 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/02 11:08:42 by Raphael          ###   ########.fr       */
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
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < 11)
	{
		while(j < 19)
		{
			ft_putnbr(tab[i][j]);
			if (tab[i][j] == 10)
				ft_putchar(' ');
			else
			{
				ft_putchar(' ');
				ft_putchar(' ');
			}
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
	return ;
}
