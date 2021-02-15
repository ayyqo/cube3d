#include "./../../includes/includes.h"
#include "./structparse.h"
#include "./../utils/libft/libft.h"

static int  is_space(int c)
{
    if (c == ' ')
        return (1);
    return (0);
}

char *delete_spaces(char *dest, char *src)
{
    size_t i;

    i = 0;
    int j = 0;
    while (src[i] != '\0')
    {
        while (is_space(src[i]))
            i++;
        dest[j] = src[i];
        i++;
        j++;
    } 
    dest[i] = '\0';
    return dest;
}