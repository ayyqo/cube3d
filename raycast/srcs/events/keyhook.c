/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezann <kezann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:14:53 by pmouhali          #+#    #+#             */
/*   Updated: 2021/02/03 10:22:53 by kezann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		move_forward(&game->player);
	if (keycode == KEY_W)
		move_backward(&game->player);
	if (keycode == KEY_S)
		move_left(&game->player);
	if (keycode == KEY_D)
		move_right(&game->player);
	if (keycode == KEY_L_ARR)
		camera_left(&game->player);
	if (keycode == KEY_R_ARR)
		camera_right(&game->player);
	if (keycode == KEY_ESC)
		exit(0);
	ft_bzero(game->img.addr, WIDTH * HEIGHT);
	return (0);
}
