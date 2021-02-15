/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezann <kezann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:14:03 by pmouhali          #+#    #+#             */
/*   Updated: 2021/02/01 20:13:48 by kezann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

extern int map[ROWS][COLS];

void	move_right(t_player *player)
{
	double ndirx;
	double ndiry;

	ndirx = player->dir_y;
	ndiry = -player->dir_x;
	if (map[(int)(player->pos_x + ndirx * MOVESPEED)][(int)player->pos_y] == 0)
		player->pos_x += ndirx * MOVESPEED;
	if (map[(int)player->pos_x][(int)(player->pos_y + ndiry * MOVESPEED)] == 0)
		player->pos_y += ndiry * MOVESPEED;
}
