/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 13:50:54 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/21 22:04:53 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_movedigit(char *str, int *i)
{
	while (str[*i] == '-' || ft_isdigit(str[*i]))
		*i = *i + 1;
	*i = *i - 1;
}

void	ft_initialize(int *i, int *j, int *l)
{
	*i = 0;
	*j = 0;
	*l = 0;
}

void	ft_increment(int *j, int *i, int *l)
{
	*j = *j + 1;
	*i = *i + 1;
	*l = 0;
}

int		**ft_parsing(char *str, t_pos *pos)
{
	int **tab;
	int i;
	int j;
	int l;

	ft_initialize(&i, &j, &l);
	tab = (int**)malloc(sizeof(int*) * (pos->line + 1));
	while (str[i])
	{
		tab[j] = (int*)malloc(sizeof(int) * (pos->nb));
		while (str[i] && str[i] != '\n')
		{
			if (ft_isdigit(str[i]) || str[i] == '-')
			{
				tab[j][l] = ft_atoi(str + i);
				l++;
				ft_movedigit(str, &i);
			}
			i++;
		}
		ft_increment(&j, &i, &l);
	}
	tab[j] = 0;
	return (tab);
}
