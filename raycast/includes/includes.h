/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezann <kezann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 09:34:23 by akezanna          #+#    #+#             */
/*   Updated: 2021/02/01 21:12:26 by kezann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INCLUDES_H_
#define _INCLUDES_H_
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <mlx.h>


# define KEY_ESC 65307
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119
# define KEY_L_ARR 65361
# define KEY_R_ARR 65363
# define ROWS 24
# define COLS 24
# define WIDTH 1920
# define HEIGHT 1080
# define texWidth 64
# define texHeight 64
# define MOVESPEED 0.65
# define ROTSPEED 0.05
# define PI 3.14159265
# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))
#define ABS(X)  fabs(X)

typedef struct	s_img
{
	void	*img;
	char	*addr;

	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct s_keys
{
    int     key_a;
    int     key_s;
    int     key_d;
    int     key_w;
    int     key_left_arr;
    int     key_right_arr;
}   t_keys;

typedef struct s_player
{
	double  pos_x;
    double  pos_y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y; 
    double  movespeed;
    double  rotspeed;
    double  oldplane_x;
    double  olddir_x;
}	t_player;

typedef struct s_ray
{
    int     x;
    int     h;
    double  camera_x;
    double  raydir_x;
    double  raydir_y;
    double  sidedist_x;
    double  sidedist_y;
    double  deltadist_x;
    double  deltadist_y;
    int     map_x;
    int     map_y;
    int     step_x;
    int     step_y;
    int     hit;
    int     side;
    double  perpwalldist;
    int     lineheight;
    int     drawstart; 
    int     drawend;
}   t_ray;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
    t_ray   ray;
    t_player player;
    
}				t_game;

void	camera_left(t_player *player);
void	camera_right(t_player *player);
void	move_forward(t_player *player);
void	move_backward(t_player *player);
void	move_left(t_player *player);
void	move_right(t_player *player);
int	    key_hook(int keycode, t_game *game);
void	ft_bzero(void *s, size_t n);
void    draw_walls(t_ray *ray, t_player *player, t_img *img);

#endif
