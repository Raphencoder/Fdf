/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:10:34 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/20 11:17:00 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "./includes/libft.h"

typedef struct	t_check
{
	int 		nb;
	int			nbl;
	int 		line;
	int			fline;
}				s_check;

typedef struct	t_pos
{
	int			x;
	float		h;
	int			movex;
	int			movey;
	float		rotatex;
	float		rotatey;
	int			y;
	int			line;
	int			nb;
	int			**tab;
	void		*win_ptr;
	void		*mlx_ptr;
	void		*ptr_img;
	char		*img_str;
	int			s_l;
}				s_pos;

typedef struct 	t_new
{
	float		x;
	float		y;
	float		z;
}				s_new;

int		**ft_parsing(char *str, s_pos *pos);
int		key_hook(int kc, s_pos *pos);
int		ft_checkgrid(char *str, s_check *numb, s_pos *pos);
void	ft_all(char *str, s_check *numb, s_pos *pos);
void	ft_get_coef(s_new corda, s_new cordb, float *coefx, float *coefy);
char	*ft_take_doc(int fd, int *line);
int		ft_graph(s_pos *pos);
#endif
