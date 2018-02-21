/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:33:49 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/21 22:03:31 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fill_pixel(int x, int y, t_pos *pos)
{
	int i;

	i = (x * 4) + (y * pos->s_l);
	if (x < pos->s_l / 4 && y < 2000 && x >= 0 && y >= 0)
	{
		if (pos->z)
		{
			pos->img_str[i + 2] = (char)58;
			pos->img_str[i + 1] = (char)58;
			pos->img_str[i] = (char)223;
		}
		else
		{
			pos->img_str[i + 2] = (char)255;
			pos->img_str[i + 1] = (char)255;
			pos->img_str[i] = (char)255;
		}
	}
}

t_new	ft_convert(int x, int y, int z, t_pos *pos)
{
	t_new new;

	x *= pos->rotatex;
	y *= pos->rotatey;
	new.x = x + pos->movex + (z * pos->h);
	new.y = y + pos->movey - (z * pos->h);
	new.z = 0;
	new.x = (int)new.x;
	new.y = (int)new.y;
	return (new);
}

void	ft_put_line(t_new corda, t_new cordb, t_pos *pos)
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

void	ft_colorandline(int i, int *j, t_pos *pos, t_new cord)
{
	if (*j > 0)
	{
		if (pos->tb[i][*j] && !pos->tb[i][*j - 1])
			pos->z = 0;
		ft_put_line(cord, ft_convert(*j - 1, i, pos->tb[i][*j - 1], pos), pos);
	}
	if (i > 0 && *j > 0)
	{
		if (pos->tb[i][*j] && (pos->tb[i - 1][*j] || pos->tb[i][*j - 1]))
			pos->z = 1;
		else
			pos->z = 0;
	}
	if (i > 0)
	{
		if (pos->tb[i][*j] && !pos->tb[i - 1][*j])
			pos->z = 0;
		ft_put_line(cord, ft_convert(*j, i - 1, pos->tb[i - 1][*j], pos), pos);
	}
	*j = *j + 1;
}

int		ft_graph(t_pos *pos)
{
	t_new	cord;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < pos->line)
	{
		while (j < pos->nb)
		{
			if (i > 0 && j > 0)
			{
				if (pos->tb[i][j] && (pos->tb[i - 1][j] || pos->tb[i][j - 1]))
					pos->z = 1;
				else
					pos->z = 0;
			}
			cord = ft_convert(j, i, pos->tb[i][j], pos);
			ft_colorandline(i, &j, pos, cord);
		}
		i++;
		j = 0;
	}
	return (0);
}
