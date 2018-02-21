/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:10:46 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/21 22:06:46 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_kczero(t_pos *pos)
{
	static int state;

	if (state == 0)
	{
		pos->rotatex -= 5;
		pos->movex += 45;
	}
	else
	{
		pos->rotatex += 5;
		pos->movex -= 45;
	}
	if (pos->rotatex < -95)
		state = 1;
	if (pos->rotatex > 95)
		state = 0;
}

void	ft_kctwo(t_pos *pos)
{
	static int stat;

	if (stat == 0)
	{
		pos->rotatex += 5;
		pos->movex -= 45;
	}
	else
	{
		pos->rotatex -= 5;
		pos->movex += 45;
	}
	if (pos->rotatex > 95)
		stat = 1;
	if (pos->rotatex < -95)
		stat = 0;
}

void	ft_kc13(t_pos *pos)
{
	static int status;

	if (status == 0)
	{
		pos->rotatey -= 5;
		pos->movey += 22;
	}
	else
	{
		pos->rotatey += 5;
		pos->movey -= 22;
	}
	if (pos->rotatey < -95)
		status = 1;
	if (pos->rotatey > 95)
		status = 0;
}

void	ft_kcsix(t_pos *pos)
{
	static int ustatee;

	if (!ustatee)
	{
		pos->rotatey -= 5;
		pos->movey += 22;
	}
	else
	{
		pos->rotatey += 5;
		pos->movey -= 22;
	}
	if (pos->rotatey < -90)
		ustatee = 1;
	if (pos->rotatey > 100)
		ustatee = 0;
}

void	handlekc(int kc, t_pos *pos)
{
	if (kc == 15)
		ft_next(pos);
	if (kc == 0)
		ft_kczero(pos);
	if (kc == 2)
		ft_kctwo(pos);
	if (kc == 13)
		ft_kc13(pos);
	if (kc == 6)
		ft_kcsix(pos);
}
