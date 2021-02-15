/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezann <kezann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:13:28 by pmouhali          #+#    #+#             */
/*   Updated: 2021/02/03 11:02:59 by kezann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

void	camera_right(t_player *player)
{
		player->olddir_x = player->dir_x;
        player->dir_x = player->dir_x * cos(-player->rotspeed) - player->dir_y * sin(-player->rotspeed);
        player->dir_y = player->olddir_x * sin(-player->rotspeed) + player->dir_y * cos(-player->rotspeed);
        player->oldplane_x = player->plane_x;
        player->plane_x = player->plane_x * cos(-player->rotspeed) - player->plane_y * sin(-player->rotspeed);
        player->plane_y = player->oldplane_x * sin(-player->rotspeed) + player->plane_y * cos(-player->rotspeed);
}
