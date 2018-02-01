/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkgrid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:08:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/01 15:53:59 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int ft_isnumb(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n' || str[i] != ' ' || (!ft_isdigit(str[i])))
			return (1);
		i++;
	}
	return (0);
}

void	ft_move(s_check *numb, char *str, int *i)
{
	if (str[*i] == '-')
		i++;
	if (!ft_isdigit(str[*i]))
		numb->col = -10;
	while (ft_isdigit(str[*i]))
		*i = *i + 1;
	*i= *i - 1;
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
			numb->col++;
		}
		if (numb->fcol && (numb->fcol != numb->col))
			break;
		numb->fcol = numb->col;
		numb->col = 0;
		i++;
		numb->fline++;
	}
	if (numb->col && (numb->fcol != numb->col))
		return (1);
	return (0);
}

int		ft_checkgrid(char *str, s_check *numb)
{
	int error;

	error = 0;
	error = ft_isnumb(str);
	error = ft_samecol(str, numb);
	error = numb->line - numb->fline;
	return (error);
}
