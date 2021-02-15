#ifndef _STRUCTPARSE_H_
#define _STRUCTPARSE_H_

typedef struct s_parsedata
{
    int     win_width;
    int     win_height;
    char    *no_text;
    char    *so_text;
    char    *ea_text;
    char    *we_text;
    char    *s_text;
    char    *ceil_col;
    char    *floor_col;
    char    **map;
    char    *tmp_map;
    int     map_cols;
    int     map_rows;
}   t_parsedata;

#endif