/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkgrid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:08:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/02 12:07:00 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

int ft_isnumb(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != ' ' && str[i] != '-' && (!ft_isdigit(str[i])))
			return (1);
		i++;
	}
	return (0);
}

void	ft_move(s_check *numb, char *str, int *i)
{
	if (str[*i] == '-')
		*i = *i + 1;
	if (!ft_isdigit(str[*i]))
		numb->nb = -100;
	while (ft_isdigit(str[*i]))
		*i = *i + 1;
	*i = *i - 1;
	numb->nb++;
	return ;
}

int		ft_samecol(char *str, s_check *numb)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] != '\n')
		{
			if (ft_isdigit(str[i]) || str[i] == '-')
				ft_move(numb, str, &i);
			if (str[i] == ' ')
				numb->space++;
			i++;
		}
		if ((numb->nbl && numb->nbl != numb->nb))
			return (1);
		numb->nbl = numb->nb;
		numb->nb = 0;
		i++;
		numb->fline++;
	}
	return (0);
}

int		ft_checkgrid(char *str, s_check *numb)
{
	int error;

	error = 0;
	error = ft_isnumb(str);
	error = error + ft_samecol(str, numb);
	error = error + numb->line - numb->fline;
	return (error);
}
