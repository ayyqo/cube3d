/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezann <kezann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:13:49 by pmouhali          #+#    #+#             */
/*   Updated: 2021/02/02 18:59:47 by kezann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

extern int map[ROWS][COLS];

void	move_backward(t_player *player)
{
	if (map[(int)(player->pos_x - player->dir_x * MOVESPEED)][(int)player->pos_y] == 0)
		player->pos_x -= player->dir_x * MOVESPEED;
	if (map[(int)player->pos_x][(int)(player->pos_y - player->dir_y * MOVESPEED)] == 0)
		player->pos_y -= player->dir_y * MOVESPEED;
}
