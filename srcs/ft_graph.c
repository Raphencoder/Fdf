/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:33:49 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/19 19:26:07 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

void        fill_pixel(int x, int y, s_pos *pos)
{
	int i;

	i = (x * 4) + (y * pos->s_l);
	if (x < pos->s_l / 4 && y < 2000 && x >= 0 && y >= 0)
	{
		pos->img_str[i + 2] = (char)255;
		pos->img_str[i + 1] = (char)255;
		pos->img_str[i] = (char)255;
	}
}

s_new	ft_convert(int x, int y, int z, s_pos *pos)
{
	s_new new;

	x *= pos->rotatex;
	y *= pos->rotatey;
	new.x = x + pos->movex + (8 * (z * pos->h));
	new.y = y + pos->movey - (5 * (z * pos->h));
	new.z = 0;
	new.x = (int)new.x;
	new.y = (int)new.y;
	return (new);
}

void	ft_get_coef(s_new corda, s_new cordb, float *coefx, float *coefy)
{
	int x;
	int y;

	x = ABS ((corda.x - cordb.x));
	y = ABS ((corda.y - cordb.y));
	if (x == 0)
	{
		*coefx = 0;
		*coefy = 1;
	}
	else if (y == 0)
	{
		*coefy = 0;
		*coefx = 1;
	}
	else
	{
		*coefx = (float)x / (float)y;
		*coefy = (float)y / (float)x;
	}
	if (*coefx >= 1)
		*coefx = 1;
	else
		*coefy = 1;
	if (cordb.x - corda.x < 0)
		*coefx = -(*coefx);
	if (cordb.y - corda.y < 0)
		*coefy = -(*coefy);
}

void	ft_put_line(s_new corda, s_new cordb, s_pos *pos)
{
	float	coefx;
	float	coefy;

	ft_get_coef(corda, cordb, &coefx, &coefy);
	if (coefy == 1 || coefy == -1)
	{
		while (cordb.y != corda.y)
		{
			fill_pixel(corda.x, corda.y, pos);
			corda.x += coefx;
			corda.y += coefy;
		}
	}
	else 
	{
		while (cordb.x != corda.x)
		{
			fill_pixel(corda.x, corda.y, pos);
			corda.x += coefx;
			corda.y += coefy;
		}
	}
}

int	ft_graph(s_pos *pos)
{
	s_new	cord;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < pos->line)
	{
		while (j < pos->nb)
		{	
			cord = ft_convert(j, i, pos->tab[i][j], pos);
			if (j > 0)
				ft_put_line(cord, ft_convert(j - 1, i, pos->tab[i][j - 1], pos), pos);
			if (i > 0)
				ft_put_line(cord, ft_convert(j, i - 1, pos->tab[i - 1][j], pos), pos);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
