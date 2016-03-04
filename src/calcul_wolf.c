/*
** calcul_wolf.c for wolf in /home/clemen_j/Work/Infographie/gfx_wolf3d
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Wed Dec 23 15:24:44 2015 Clémenceau Cedric
** Last update Wed Jan  6 09:54:59 2016 Clémenceau Cedric
*/

#include "struct.h"

t_bunny_response	maccro_key(t_bunny_event_state state,
				   t_bunny_keysym key,
				   t_info *data)
{
  if (state == GO_DOWN)
    {
      if (key == BKS_ESCAPE)
	{
	  my_freebox(data);
	  return (EXIT_ON_SUCCESS);
	}
      if (key == BKS_UP)
	move_up(data);
      if (key == BKS_DOWN)
	move_down(data);
      if (key == BKS_LEFT)
	move_left(data);
      if (key == BKS_RIGHT)
	move_right(data);
    }
  return (GO_ON);
}

t_bunny_response	main_loop(t_info *data)
{
  start(data->pix);
  calc(data);
  bunny_blit(&data->win->buffer, &data->pix->clipable, NULL);
  bunny_display(data->win);
  return (GO_ON);
}

void	move_up(t_info *data)
{
  if (data->map[(int)(DPY + sin(ANGLE) / 5)][(int)(DPX + cos(ANGLE) / 5)] != 1)
    {
      data->pos.x = (data->pos.x + cos(ANGLE) / 5);
      data->pos.y = (data->pos.y + sin(ANGLE) / 5);
    }
}

void	move_down(t_info *data)
{
  if (data->map[(int)(DPY - sin(ANGLE) / 5)][(int)(DPX - cos(ANGLE) / 5)] != 1)
    {
      data->pos.x = (data->pos.x - cos(ANGLE) / 5);
      data->pos.y = (data->pos.y - sin(ANGLE) / 5);
    }
}

void	move_left(t_info *data)
{
  ANGLE += 0.2;
}

void	move_right(t_info *data)
{
  ANGLE -= 0.2;
}

void	my_freebox(t_info *data)
{
  int	y;

  y = 0;
  while (y < data->height)
    {
      bunny_free(data->map[y]);
      y++;
    }
  bunny_delete_clipable(&data->pix->clipable);
  bunny_stop(data->win);
  bunny_free(data->map);
}
