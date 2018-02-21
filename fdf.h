/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:10:34 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/21 22:08:57 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "./includes/libft.h"

typedef struct	s_check
{
	int			nb;
	int			nbl;
	int			line;
	int			fline;
}				t_check;

typedef struct	s_pos
{
	int			x;
	float		h;
	int			z;
	int			bpp;
	int			endian;
	int			movex;
	int			movey;
	float		rotatex;
	float		rotatey;
	int			y;
	int			line;
	int			nb;
	int			**tb;
	void		*win_ptr;
	void		*mlx_ptr;
	void		*ptr_img;
	char		*img_str;
	int			s_l;
}				t_pos;

typedef struct	s_new
{
	float		x;
	float		y;
	float		z;
}				t_new;

int				**ft_parsing(char *str, t_pos *pos);
void			handlekc(int kc, t_pos *pos);
void			ft_next(t_pos *pos);
int				key_hook(int kc, t_pos *pos);
int				ft_checkgrid(char *str, t_check *numb, t_pos *pos);
int				ft_all(char *str, t_check *numb, t_pos *pos);
void			ft_get_coef(t_new corda, t_new cordb,
float *coefx, float *coefy);
char			*ft_take_doc(int fd, int *line);
int				ft_graph(t_pos *pos);
#endif
