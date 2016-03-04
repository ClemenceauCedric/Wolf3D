/*
** go.c for wolf in /home/clemen_j/Work/Infographie/gfx_wolf3d/tcore
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Sun Dec 27 21:14:06 2015 Clémenceau Cedric
** Last update Sun Dec 27 21:19:44 2015 Clémenceau Cedric
*/

#include "struct.h"

void	go(t_bunny_position *curpos,
	   double angle,
	   t_bunny_position *newpos,
	   int move)
{
  newpos->x = curpos->x + cos(angle) * move;
  newpos->y = curpos->y + sin(angle) * move;
}
