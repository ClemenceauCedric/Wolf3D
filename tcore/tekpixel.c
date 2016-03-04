/*
1;2802;0c** tekpixel.c for liblapin in /home/clemen_j/tek1/infographie/gfx_fdf1/src
**
** Made by Cédric Clemenceau
** Login   <clemen_j@epitech.net>
**
** Started on  Fri Nov 20 18:31:15 2015 Cédric Clemenceau
** Last update Sun Dec 27 18:55:07 2015 Clémenceau Cedric
*/

#include "struct.h"

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color)
{
  t_color	*col;
  int		stock;

  stock = pos->y * pix->clipable.clip_width + pos->x;
  if (stock >= 0 && stock < WIDTH * HEIGHT)
  {
      col = (t_color*) pix->pixels + stock;
      col->full = color->full;
  }
}
