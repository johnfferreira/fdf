# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joferrei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/14 12:14:32 by joferrei          #+#    #+#              #
#    Updated: 2025/10/14 12:14:33 by joferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEADER = ./src/fdf.h
SRC_DIR       = src
SRC_GN_DIR    = gn
OBJ_DIR       = obj

SRC       = fdf.c ft_atol.c ft_draw_painel.c ft_isometric.c ft_split.c parse_map.c ft_bzero.c ft_event.c util.c get_map_height.c ft_strncmp.c ft_error.c ft_putstr_fd.c ft_strtrim.c ft_event2.c
SRC_GN    = get_next_line_utils.c get_next_line.c

CC     = cc
CFLAGS = -Wall -Wextra -Werror -g
RM     = rm -f

# MiniLibX
MLX_DIR   = minilibx-linux
MLX_FLAGS = -I$(MLX_DIR)
MLX_LIBS  = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

OBJ_MANDATORY = $(addprefix $(OBJ_DIR)/src/,$(SRC:.c=.o)) \
				$(addprefix $(OBJ_DIR)/gn/,$(SRC_GN:.c=.o))

# ficheiros binários intermédios (evita regras conflitantes em $(NAME))
BUILD_src = $(NAME)

# alvo padrão
all: src

# src: gera build/fdf_src e copia para fdf apenas se necessário
src: $(NAME)
	@if [ ! -e $(NAME) ]; then \
		echo ">>> $(NAME) buildado:"; \
	else \
		echo ">>> $(NAME) ja esta buildado (fdf)"; \
	fi
$(MLX_DIR)/libmlx_Linux.a:
	@make -C $(MLX_DIR)

$(NAME): $(OBJ_MANDATORY) | $(MLX_DIR)/libmlx_Linux.a
	$(CC) $(CFLAGS) $(OBJ_MANDATORY) -o $@ $(MLX_FLAGS) $(MLX_LIBS)

$(OBJ_DIR)/src/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $@

$(OBJ_DIR)/gn/%.o: $(SRC_GN_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(MLX_DIR) clean

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all src bonus clean fclean re
