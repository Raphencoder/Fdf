/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:10:34 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/01 16:13:58 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./includes/libft.h"

typedef struct	t_check
{
	int 		col;
	int 		fcol;
	int 		nb;
	int			nbl;
	int 		space;
	int 		line;
	int			fline;
}				s_check;

int		**ft_parsing(char *str, s_check *numb);
int		ft_checkgrid(char *str, s_check *numb);
void	ft_all(char *str, s_check *numb);
char	*ft_take_doc(int fd, int *line);
#endif
