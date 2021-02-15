#include "./../../includes/includes.h"

extern int map[ROWS][COLS];

static void    player_moveforward(t_player *player)
{
    if(map[(int)(player->pos_x + player->dir_x * player->movespeed)][(int)(player->pos_y)] == 0) player->pos_x += player->dir_x * player->movespeed;
    if(map[(int)(player->pos_x)][(int)(player->pos_y + player->dir_y * player->movespeed)] == 0) player->pos_y += player->dir_y * player->movespeed;
}

static void    player_movebackward(t_player *player)
{
    if(map[(int)(player->pos_x - player->dir_x * player->movespeed)][(int)(player->pos_y)] == 0) player->pos_x -= player->dir_x * player->movespeed;
    if(map[(int)(player->pos_x)][(int)(player->pos_y - player->dir_y * player->movespeed)] == 0) player->pos_y -= player->dir_y * player->movespeed;
}

static void    player_turnright(t_player *player)
{
        player->olddir_x = player->dir_x;
        player->dir_x = player->dir_x * cos(-player->rotspeed) - player->dir_y * sin(-player->rotspeed);
        player->dir_y = player->olddir_x * sin(-player->rotspeed) + player->dir_y * cos(-player->rotspeed);
        player->oldplane_x = player->plane_x;
        player->plane_x = player->plane_x * cos(-player->rotspeed) - player->plane_y * sin(-player->rotspeed);
        player->plane_y = player->oldplane_x * sin(-player->rotspeed) + player->plane_y * cos(-player->rotspeed);
}

static void    player_turnleft(t_player *player)
{
        player->olddir_x = player->dir_x;
        player->dir_x = player->dir_x * cos(player->rotspeed) - player->dir_y * sin(player->rotspeed);
        player->dir_y = player->olddir_x * sin(player->rotspeed) + player->dir_y * cos(player->rotspeed);
        player->oldplane_x = player->plane_x;
        player->plane_x = player->plane_x * cos(player->rotspeed) - player->plane_y * sin(player->rotspeed);
        player->plane_y = player->oldplane_x * sin(player->rotspeed) + player->plane_y * cos(player->rotspeed);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		move_forward(game->player);
	if (keycode == KEY_W)
		move_backward(game->player);
	if (keycode == KEY_S)
		move_left(game->player);
	if (keycode == KEY_D)
		move_right(game->player);
	if (keycode == KEY_L_ARR)
		camera_left(game->player);
	if (keycode == KEY_R_ARR)
		camera_right(game->player);
	if (keycode == KEY_ESC)
		exit(0);
	ft_bzero(game->img.addr, WIDTH * HEIGHT);
	return (0);
}

