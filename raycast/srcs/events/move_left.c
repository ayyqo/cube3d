/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezann <kezann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:14:09 by pmouhali          #+#    #+#             */
/*   Updated: 2021/02/01 20:02:23 by kezann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

extern int map[ROWS][COLS];

void	move_left(t_player *player)
{
	double ndir_x;
	double ndir_y;

	ndir_x = -player->dir_y;
	ndir_y = player->dir_x;
	if (map[(int)(player->pos_x + ndir_x * MOVESPEED)][(int)player->pos_y] == 0)
		player->pos_x += ndir_x * MOVESPEED;
	if (map[(int)player->pos_x][(int)(player->pos_y + ndir_y * MOVESPEED)] ==  0)
		player->pos_y += ndir_y * MOVESPEED;
}
