#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_ceil_floor
{
    char    *ceilcolor;
    char    *floorcolor;
}   t_ceil_floor;

typedef struct s_map
{
    int     **map;
    char    *map;
    int     cols;
    int     rows;
}   t_map;

typedef struct	s_img
{
	void	*img;
	char	*addr;
    char    *path_to_notx;
    char    *path_to_sotx;
    char    *path_to_eatx;
    char    *path_to_wetx;
	int		size_l;
	int		bpp;
	int		endian;
    int     width;
    int     height;
}				t_img;

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

typedef struct s_window
{
	void	*win;
	int		width;
	int		height;
}	t_window;

typedef struct	s_game
{
	void	*mlx;
	t_img	img;
    t_ray   ray;
    t_player player;
    t_window window;
    
}				t_game;

#endif