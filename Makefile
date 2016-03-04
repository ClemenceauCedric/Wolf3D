##
## Makefile for liblapin in /home/clemen_j/tek1/infographie/gfx_fdf1
##
## Made by Cédric Clemenceau
## Login   <clemen_j@epitech.net>
##
## Started on  Fri Nov 20 19:12:10 2015 Cédric Clemenceau
## Last update Sun Dec 27 20:58:57 2015 Clémenceau Cedric
##

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-I./include/
CFLAGS	+=	-g -W -Wall -Wextra -ansi -pedantic

LIB	=	-L/home/${USER}/.froot/lib \
		-L/usr/local/lib \
		-llapin \
		-lsfml-audio \
		-lsfml-graphics \
		-lsfml-window \
		-lsfml-system \
		-lstdc++ -ldl \
		-lm

SRC	=	src/my_getnbr.c \
		src/tekpixel.c \
		src/wolf.c \
		src/calcul_angle.c \
		src/calcul_wolf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	wolf3d

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) $(LIB) -o $(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
