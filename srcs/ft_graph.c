/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:33:49 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/12 20:30:55 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void        fill_pixel(int x, int y, s_check *numb, char *img_str)
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

s_new	ft_convert(int x, int y, int z, s_cam *cam)
{
	s_new new;

	new.x = cam->x - x;
	new.y = cam->y - y;
	if (!z)
		return (new);
	new.z = cam->z - z;
	new.x = new.x * (-(cam->z) / z);
	new.y = new.y * (-(cam->z) / z);
	new.x = new.x + cam->x;
	new.y = new.y + cam->y;
	new.z = 0;
	return (new):
}

int	ft_graph(int **tab, s_check *numb)
{
	s_pos	pos;
	s_cam	cam;
	s_new	cord;
	s_new	tmp;
	int		i;
	int		j;

	pos.mlx_ptr = mlx_init();
	pos.win_ptr = mlx_new_window(pos.mlx_ptr, 3000, 2000, "fdf");
	while (i < numb->line)
	{
		while (j < numb->nbl)
		{	
			cord = ft_convert(j, i, tab[i][j], &cam);
			if (j > 0)
				ft_put_line(cord, ft_convert(j - 1, i, tab[i][j - 1], &cam));
			if (i > 0)
				ft_put_line(cord, ft_convert(j, i - 1, tab[i - 1][j], &cam));
				
			tmp = cord;
			j++;
		}
	}
	ft_doanimg(tab, numb, &pos);
	mlx_loop(pos.mlx_ptr);
	return (0);
}
