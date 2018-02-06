/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:33:49 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/06 22:08:01 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void        fill_pixel(int x, int y, s_check *numb, char *img_str)
{
	int i;
	
	i = (x * 4) + (y * numb->nbl);
	if (x < (numb->nbl / 4) && y < (numb->nbl / 4) && x > 0 && y > 0)
	{
		img_str[i + 2] = 0;
		img_str[i + 1] = 0;
		img_str[i] = 0;
	}
}

void	ft_bresenham(int x1, int y1, int x2, int y2, s_check *numb, char *img_str, void *mlx_ptr, void *win_ptr)
{
	int x;
	int y;

	(void)numb;
	(void)img_str;
	x = x1 - x2;
	y = y1 - y2;
	x = ABS(x);
	y = ABS(y);
	if (x > y)
	{
		if (x1 > x2)
		{
			ft_swap(&x1, &x2);
			ft_swap(&y1, &y2);
		}
		x = x1;
		while (x < x2)
		{
			y = y1 + ((y2 - y1) * (x - x1)) / (x2 - x1);
//			fill_pixel(x, y, numb, img_str);
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0XFFFFFF);
			x++;
		}
	}
	else
	{
		if (y1 >= y2)
		{
			ft_swap(&x1, &x2);
			ft_swap(&y1, &y2);
		}
		x = x1;
		while (x < x2)
		{
			y = y1 + ((y2 - y1) * (x - x1)) / (x2 - x1);
	//		fill_pixel(x, y, numb, img_str);
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0XFFFFFF);
			x++;
		}
	}
}


int ft_algo2(s_check *numb, char *img_str, int **tab, void *mlx_ptr, void *win_ptr)
{
	int	h;
	int	x;
	int y;
	int i;
	int j;

	x = 500;
	y = 500;
	i = 0;
	j = 0;
	while (j < numb->nbl)
	{
		while (i < numb->line)
		{
			clonex = x;
			h = tab[i][j];
			if (numb->oldy)
				y = numb->oldy + 10;
			else
				y = y + 10;
			if (numb->oldy)
				ft_bresenham(x, y, numb->oldx, numb->oldy, numb, img_str, mlx_ptr, win_ptr);
			numb->oldx = x;
			numb->oldy = y;
			i++;
		}
		i = 0;
		j++;
		y = 500;
		x = clonex + 20;
		numb->oldx = 0;
		numb->oldy = 0;
	}
	return (0);
}

int	ft_algo(s_check *numb, char *img_str, int **tab, void *mlx_ptr, void *win_ptr)
{
	int	h;
	int	x;
	int y;
	int i;
	int j;
	int	flag;
	int	cloney;
	int clonex;

	x = 850;
	y = 850;
	i = 0;
	j = 0;
	flag = 0;
	while (i < numb->line)
	{
		cloney = y;
		clonex = x;
		while (j < numb->nbl)
		{
			h = tab[i][j];
			if (numb->oldx)
				x = numb->oldx + 20;
			else
				x = x + 20;
			if (numb->oldy)
				ft_bresenham(x, y + h, numb->oldx, numb->oldy, numb, img_str, mlx_ptr, win_ptr);
			numb->oldx = x;
			numb->oldy = y + h;
			j++;
		}
		j = 0;
		i++;
		x = 850;
		y = cloney + 20;
		numb->oldy = 0;
		numb->oldx = 0;
	}
	return (0);
}

int	ft_doanimg(int **tab, s_check *numb, void *mlx_ptr, void *win_ptr)
{
//	void	*ptr_img;
	char	*img_str;
//	int		s_l;
//	int		bpp;
//	int		endian;

	img_str = 0;
//	ptr_img = mlx_new_image(mlx_ptr, numb->nbl, numb->line);
//	img_str = mlx_get_data_addr(mlx_ptr, &(bpp), &(s_l), &(endian));
	ft_algo(numb, img_str, tab, mlx_ptr, win_ptr);
	ft_algo2(numb, img_str, tab, mlx_ptr, win_ptr);
//	mlx_put_image_to_window(mlx_ptr, win_ptr, ptr_img, 0, 0);
	return (0);
}	

int	ft_graph(int **tab, s_check *numb)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1500, 1500, "fdf");
	ft_doanimg(tab, numb, mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
