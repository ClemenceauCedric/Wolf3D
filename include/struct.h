/*
** my.h for fdf1 in /home/clemen_j/tek1/infographie/gfx_fdf1/my
**
** Made by Cédric Clemenceau
** Login   <clemen_j@epitech.net>
**
** Started on  Fri Nov 20 16:32:21 2015 Cédric Clemenceau
** Last update Mon Dec 28 21:02:46 2015 Clémenceau Cedric
*/

#ifndef STRUCT_H_
# define STRUCT_H_
# define WIDTH 800
# define HEIGHT 600
# define SKY BLUE
# define GROUND 0x009966
# define WALL 0x3B3A3A
# define INI (char *)bunny_ini_get_field
# define P 1
# define POSX data->pos1.x
# define POSY data->pos1.y
# define MAP data->map
# define TMP data->pos2
# define ANGLE data->pos.angle
# define SIN data->cos.tab_sin
# define COS data->cos.tab_sin
# define DPX data->pos.x
# define DPY data->pos.y

# include <unistd.h>
# include <math.h>
# include <lapin.h>

typedef struct			s_cos
{
  double			tab_cos[360];
  double			tab_sin[360];
}				t_cos;

typedef struct			s_pos2
{
  double			x;
  double			y;
}				t_pos2;

typedef struct			s_pos
{
  double			x;
  double			y;
  double			angle;
}				t_pos;

typedef struct			s_info
{
  int				**map;
  int				width;
  int				height;
  t_bunny_window		*win;
  t_bunny_pixelarray		*pix;
  t_bunny_position		pos_pix;
  t_color			color;
  t_bunny_ini			*ini;
  t_bunny_accurate_position	pos1;
  t_pos			    	pos;
  t_pos2			pos2;
  t_cos				cos;

}				t_info;

void	tekpixel(t_bunny_pixelarray *,
		 t_bunny_position *,
		 t_color *);
int	read_ini(char *, t_info *);
int	my_getnbr(char *);
int	tab(t_info *);
void	calc_cos(t_info *);
void	calc_sin(t_info *);
int	check_ini(t_info *, char *);
void	calc(t_info *);
void	my_wall(t_info *, int, int);
int	my_put_nbr(int);
void	print_tab(int **, t_info *);
void	move_up(t_info *);
int	start(t_bunny_pixelarray *);
void	move_up(t_info *);
void	move_down(t_info *);
void	move_left(t_info *);
void	move_right(t_info *);
void	my_freebox(t_info *);
t_bunny_response	main_loop(t_info *);
t_bunny_response	maccro_key(t_bunny_event_state, t_bunny_keysym , t_info *);

#endif /* !STRUCT_H_ */
