#include "./../../includes/includes.h"

extern int map[ROWS][COLS];

static void            my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->size_l + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

static void    get_sidedistances(t_ray *ray, t_player *player)
{
        if (ray->raydir_x < 0)
        {
            ray->step_x = -1;
            ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
        }
        else
        {
            ray->step_x = 1;
            ray->sidedist_x = (player->pos_x + 1.0 - ray->map_x) * ray->deltadist_x;
        }
        if (ray->raydir_y < 0)
        {
            ray->step_y = -1;
            ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
        }
        else
        {
            ray->step_y = 1;
            ray->sidedist_y = (player->pos_y + 1.0 - ray->map_y) * ray->deltadist_y;
        }
}

static void     dda(t_ray *ray)
{
        while (ray->hit == 0)
		{
			if (ray->sidedist_x < ray->sidedist_y)
			{
				ray->sidedist_x += ray->deltadist_x;
				ray->map_x += ray->step_x;
				ray->side = 0;
			}
			else
			{
				ray->sidedist_y += ray->deltadist_y;
				ray->map_y += ray->step_y;
				ray->side = 1;
			}
			if (map[ray->map_x][ray->map_y] == 1) ray->hit = 1;
		}
}

static void    get_perp(t_ray *ray, t_player *player)
{
        ray->h = HEIGHT;
        if (ray->side == 0)
			ray->perpwalldist = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->raydir_x;
		else
			ray->perpwalldist = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->raydir_y;
		ray->lineheight = (int)(ray->h / ray->perpwalldist);
		ray->drawstart = -ray->lineheight / 2 + ray->h / 2;
		if (ray->drawstart < 0) ray->drawstart = 0;
		ray->drawend = ray->lineheight / 2 + ray->h / 2;
		if (ray->drawend < 0) ray->drawend = ray->h - 1;
}

static void     init_ray(t_ray *ray, t_player *player)
{
        ray->camera_x = 2 * ray->x /(double)WIDTH - 1;
        ray->raydir_x = player->dir_x + player->plane_x * ray->camera_x;
        ray->raydir_y = player->dir_y + player->plane_y * ray->camera_x;
        ray->map_x = (int)player->pos_x;
        ray->map_y = (int)player->pos_y;
        ray->hit = 0;
        ray->deltadist_x = fabs(1 / ray->raydir_x);
        ray->deltadist_y = fabs(1 / ray->raydir_y);
        ray->lineheight = 0;
        get_sidedistances(ray, player);
}
void    draw_walls(t_ray *ray, t_player *player, t_img *img)
{
        ray->x = 0;
        int color = 982475;
        
        while (ray->x < WIDTH)
        {
            init_ray(ray, player);
            dda(ray);
            get_perp(ray, player);
            while (ray->drawstart < ray->drawend)
            {
                my_mlx_pixel_put(img, ray->x, ray->drawstart, color);
                ray->drawstart++;
            }
            ray->x++;
        }
}
