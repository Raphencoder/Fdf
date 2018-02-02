/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 13:50:54 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/02 11:08:02 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_movedigit(char *str, int *i)
{
	while (str[*i] == '-' || ft_isdigit(str[*i]))
		*i = *i + 1;
	*i = *i - 1;
}

int		**ft_parsing(char *str, s_check *numb)
{
	int **tab;
	int i;
	int j;
	int l;

	i = 0;
	l = 0;
	j = 0;
	tab = (int**)malloc(sizeof(int*) * (numb->line + 1));
	while (str[i])
	{
		tab[j] = (int*)malloc(sizeof(int) * (numb->nbl));
		while(str[i] && str[i] != '\n')
		{
			if (ft_isdigit(str[i]) || str[i] == '-')
			{
				tab[j][l] = ft_atoi(str + i);
				l++;
				ft_movedigit(str, &i);
			}
			i++;
		}
		l = 0;
		j++;
		i++;
	}
	tab[j] = 0;
	return (tab);
}
