/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:33:49 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/15 20:35:55 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

/*void        fill_pixel(int x, int y, s_check *numb, char *img_str)
  {
  int i;

  i = (x * 4) + (y * 4 * numpos->nbl);
  if (x < (numpos->nbl / 4) && y < (numpos->nbl / 4) && x > 0 && y > 0)
  {
  img_str[i + 2] = 0;
  img_str[i + 1] = 0;
  img_str[i] = 0;
  }
  }

  int	ft_doanimg(int **tab, s_check *numb, s_pos *pos)
  {
//	void	*ptr_img;
char	*img_str;

//	int		s_l;
//	int		bpp;
//	int		endian;

img_str = 0;
// 	ptr_img = mlx_new_image(mlx_ptr, numpos->nbl, numpos->line);
//	img_str = mlx_get_data_addr(mlx_ptr, &(bpp), &(s_l), &(endian));
//	mlx_put_image_to_window(mlx_ptr, win_ptr, ptr_img, 0, 0);
return (0);
}	
*/
s_new	ft_convert(int x, int y, int z, s_cam *cam)
{
	s_new new;

	new.x = x * 100 + 150;
	new.y = y * 100 + 150;
	cam->x = 100;
	cam->y = 100;
	cam->z = 10.5;
	if (!z)
		return (new);
	new.x = (new.x - cam->x) / z * cam->z;
	new.y = (new.y - cam->y) / z * cam->z;
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

void	ft_put_line(s_new corda, s_new cordb, s_pos pos)
{
	float	coefx;
	float	coefy;

	ft_get_coef(corda, cordb, &coefx, &coefy);
	printf("corda.x = %f, cordb.x = %f\n", corda.x, cordb.x);
	printf("corda.y = %f, cordb.y = %f\n", corda.y, cordb.y);
	printf("coefy = %f, coefx = %f\n", coefy, coefx);
	if (coefy == 1 || coefy == -1)
	{
		while (cordb.y != corda.y)
		{
			mlx_pixel_put(pos.mlx_ptr, pos.win_ptr, corda.x, corda.y, 0xFFFFFFF);
			corda.x += coefx;
			corda.y += coefy;
		}
	}
	else 
	{
		while (cordb.x != corda.x)
		{
			mlx_pixel_put(pos.mlx_ptr, pos.win_ptr, corda.x, corda.y, 0xFFFFFF);
			corda.x += coefx;
			corda.y += coefy;
		}
	}
}

int	ft_graph(int **tab, s_check *numb)
{
	s_pos	pos;
	s_cam	cam;
	s_new	cord;
	int		i;
	int		j;

	pos.mlx_ptr = mlx_init();
	pos.win_ptr = mlx_new_window(pos.mlx_ptr, 3000, 2000, "fdf");
	j = 0;
	i = 0;
	while (i < numb->line)
	{
		while (j < numb->nbl)
		{	
			cord = ft_convert(j, i, tab[i][j], &cam);
			if (j > 0)
				ft_put_line(cord, ft_convert(j - 1, i, tab[i][j - 1], &cam), pos);
			if (i > 0)
				ft_put_line(cord, ft_convert(j, i - 1, tab[i - 1][j], &cam), pos);
			j++;
		}
		i++;
		j = 0;
	}
	ft_putnbr(numb->nbl);
	//	ft_doanimg(tab, numb, &pos);
	mlx_loop(pos.mlx_ptr);
	return (0);
}
