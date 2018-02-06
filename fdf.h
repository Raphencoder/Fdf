/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:10:34 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/05 18:32:03 by rkrief           ###   ########.fr       */
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
	int 		space;
	int			lspace;
	int 		line;
	int			fline;
	int			oldx;
	int			oldy;
}				s_check;

int		**ft_parsing(char *str, s_check *numb);
int		ft_checkgrid(char *str, s_check *numb);
void	ft_all(char *str, s_check *numb);
char	*ft_take_doc(int fd, int *line);
int		ft_graph(int **tab, s_check *numb);
#endif
