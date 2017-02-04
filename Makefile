# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvoina <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 10:05:52 by mvoina            #+#    #+#              #
#    Updated: 2015/12/10 23:08:59 by mvoina           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRC =  source/rtv1.c\
       source/hooks.c\
       source/vectors.c\
       source/vectors_2.c\
       source/sphere.c\
       source/cylinder.c\
       source/cone.c\
       source/plane.c\
       source/scene_ini.c\
       source/scenes/scene_one.c\
       source/scenes/scene_two.c\
       source/scenes/scene_three.c\
       source/scenes/scene_four.c\
       source/scenes/scene_five.c\
       source/scenes/scene_six.c\
       source/scenes/scene_seven.c\
       source/scenes/scene_eight.c\
       source/scenes/scene_nine.c\
       source/scene_creator.c\
       source/light.c\
       source/rotate.c\
       source/set_angle.c\
       source/intersect.c\
       source/rtracer.c\
       source/helper_matrix.c\

OBJ = rtv1.o\
      hooks.o\
      vectors.o\
      vectors_2.o\
      sphere.o\
      cylinder.o\
      cone.o\
      plane.o\
      scene_ini.o\
      scene_one.o\
      scene_two.o\
      scene_three.o\
      scene_four.o\
      scene_five.o\
      scene_six.o\
      scene_seven.o\
      scene_eight.o\
      scene_nine.o\
      scene_creator.o\
      light.o\
      rotate.o\
      set_angle.o\
      intersect.o\
      rtracer.o\
      helper_matrix.o\

FLAGS = -Wall -Wextra -Werror

MLX = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

LIBFT = -L libft/ -lft

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc -c $(SRC) $(FLAGS)
	@gcc $(OBJ) $(MLX) $(LIBFT) -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
