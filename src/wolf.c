/*
** wolf.c for wolf in /home/clemen_j/Work/Infographie/gfx_wolf3d/src
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Tue Dec 22 03:07:25 2015 Clémenceau Cedric
** Last update Wed Jan  6 09:54:55 2016 Clémenceau Cedric
*/

#include "struct.h"

int	tab(t_info *data)
{
  int	i;

  i = data->width;
  if ((data->map = bunny_malloc(sizeof(int *) * data->height)) == NULL)
    return (1);
  while (i >= 0)
    {
      if ((data->map[i] = bunny_malloc(sizeof(int) * data->width)) == NULL)
	return (1);
      i--;
    }
  return (0);
}

int	check_ini(t_info *data, char *av)
{
  if ((data->ini = bunny_load_ini(av)) == 0)
    return (1);
  if ((data->width =
       my_getnbr(INI(data->ini, "level1", "width", 0))) == 0)
    return (1);
  if ((data->height =
       my_getnbr(INI(data->ini, "level1", "height", 0))) == 0)
    return (1);
  if ((data->pos.x =
       my_getnbr(INI(data->ini, "level1", "start_position",  0))) == 0)
    return (1);
  if ((data->pos.y =
       my_getnbr(INI(data->ini, "level1", "start_position", 1))) == 0)
    return (1);
  if ((ANGLE =
       my_getnbr(INI(data->ini, "level1", "start_position", 2))) == 0)
    return (1);
  ANGLE = ANGLE * M_PI / 180;
  return (0);
}

int	read_ini(char *av, t_info *data)
{
  int	i;
  int	j;
  int	z;

  check_ini(data, av);
  tab(data);
  i = data->height - 1;
  j = 0;
  while (i >= 0)
    {
      z = data->width - 1;
      while (z >= 0)
	{
	  data->map[i][z--] =
	    my_getnbr((char *)INI(data->ini, "level1", "data", j++));
	}
      i--;
    }
  return (0);
}

int		start(t_bunny_pixelarray *pix)
{
  t_color	*color;
  int		n;

  n = 0;
  while (n < (pix->clipable.clip_width * pix->clipable.clip_height) / 2)
    {
      color = (t_color*)pix->pixels + n;
      color->full = SKY;
      n++;
    }
  while (n < (pix->clipable.clip_width * pix->clipable.clip_height))
    {
      color = (t_color*)pix->pixels + n;
      color->full = GROUND;
      n++;
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_info	data;

  if (ac != 2)
    {
      write(1, "too few/many args\n", 18);
      return (1);
    }
  data.pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  data.win = bunny_start(WIDTH, HEIGHT, false, "wolf3d");
  if ((read_ini(av[1], &data)) == 1)
    return (1);
  data.pos.x = data.pos.x + 0.5;
  data.pos.y = data.pos.y + 0.5;
  bunny_set_loop_main_function((t_bunny_loop)main_loop);
  bunny_set_key_response((t_bunny_key)&maccro_key);
  bunny_loop(data.win, 25, &data);
  return (0);
}
