/*
** calcul_angle.c for wolf in /home/clemen_j/Work/Infographie/gfx_wolf3d
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Wed Dec 23 16:53:43 2015 Clémenceau Cedric
** Last update Sun Dec 27 20:55:20 2015 Clémenceau Cedric
*/

#include "struct.h"

void	my_wall(t_info *data, int x, int wall_height)
{
  data->color.full = WALL;
  data->pos_pix.x = x;
  data->pos_pix.y = (HEIGHT / 2 - wall_height);
  while (data->pos_pix.y < ((HEIGHT / 2) + wall_height))
    {
      tekpixel(data->pix, &data->pos_pix, &data->color);
      (data->pos_pix.y)++;
    }
}

void		calc(t_info *data)
{
  double	x;
  double	y;
  double	k;

  x = 0;
  while (x < WIDTH)
    {
      k = 0;
      y = ((((double)WIDTH / 2) - x) / (double)WIDTH);
      POSX = ((0.5 * (cos(ANGLE))) - ((double)y * (sin(ANGLE))));
      POSY = ((0.5 * (sin(ANGLE))) + ((double)y * (cos(ANGLE))));
      TMP.y = data->pos.y;
      TMP.x = data->pos.x;
      while (MAP[(int)TMP.y][(int)TMP.x] == 0)
      	{
      	  TMP.x = data->pos.x + (k * POSX);
      	  TMP.y = data->pos.y + (k * POSY);
      	  k += 0.01;
      	}
      my_wall(data, x, (HEIGHT / (2 * k)));
      x++;
    }
}
