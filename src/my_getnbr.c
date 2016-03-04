/*
** my_getnbr.c for get_nbr in /home/clemen_j/rendu/Piscine_C_J04
**
** Made by Cédric Clemenceau
** Login   <clemen_j@epitech.net>
**
** Started on  Sun Oct 11 08:07:34 2015 Cédric Clemenceau
** Last update Tue Dec 22 03:15:40 2015 Clémenceau Cedric
*/

#include "struct.h"

int	my_getnbr(char *str)
{
  int	nb;
  int	i;
  int	count;

  nb = 0;
  i = 0;
  count = 0;
  while (str[i] == '-' || str[i] == '+')
    count++;
  while (str[i])
    {
      nb = 10 * nb + (str[i] - 48);
      i++;
    }
  if (nb == -2147483648)
    write(1, "-2147483648", 11);
  else
    if (count%2 == 1)
      nb = -nb;
  return (nb);
}
