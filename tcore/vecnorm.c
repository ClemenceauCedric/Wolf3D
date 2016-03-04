/*
** vecnorm.c for wolf in /home/clemen_j/Work/Infographie/gfx_wolf3d/tcore
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Sun Dec 27 21:03:08 2015 Clémenceau Cedric
** Last update Sun Dec 27 21:12:33 2015 Clémenceau Cedric
*/

#include "struct.h"

double		vecnorm(t_bunny_position *coord0,
			t_bunny_position *coord1)
{
  double	x;
  double	y;
  double	tmp;

  x = (coord1->x)*(coord1->x) - (coord0->x)*(coord0->x);
  y = (coord1->y)*(coord1->y) - (coord0->y)*(coord0->y);
  tmp = sqrt(x + y);
  return (tmp);
}
