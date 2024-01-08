# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 19:22:29 by bfaure            #+#    #+#              #
#    Updated: 2024/01/08 19:22:29 by bfaure           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	cub3D

LIBFT		=	libft.a

LIBMLX		=	libmlx.a

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	=	./src/

DIR_MLX		=	minilibx-linux/

DIR_LIBFT	=	${DIR_SRCS}utils/Libft/

LIBFT_A = $(DIR_LIBFT)$(LIBFT)

MLXLIB_A = $(DIR_MLX)$(LIBMLX)

# ---- Files ---- #

SRCS			=	main.c /
					utils/garbage_collector/gc_fonc.c /
					utils/garbage_collector/gc_init.c /


OBJS = ${SRCS:%.c=${DIR_OBJS}%.o}

DEPS = ${SRCS:%.c=${DIR_OBJS}%.d}

# ---- Compilation ---- #

DEPS_FLAGS = -MMD -MP

CC		=	cc

CFLAGS	=	${DEPS_FLAGS} -Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ********* RULES ******** #

all		: ${NAME}

$(LIBFT_A):	force
	@ ${MAKE} ${LIBFT} -C ${DIR_LIBFT} -j4

$(MLXLIB_A): force
	@ ${MAKE} ${LIBMLX} -C ${DIR_MLX} -j4

.PHONY:	all clean fclean re fclean_lib fclean_all force

# ---- Variables Rules ---- #

${NAME}	:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_LIBFT} -L${DIR_MLX}

# ---- Compiled Rules ---- #

-include ${DEPS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c $(LIBFT_A) $(MLXLIB_A)
					@${MKDIR} $(shell dirname $@) #${DIR_OBJS}
					${CC} ${CFLAGS} -I $(DIR_LIBFT) -I ${DIR_MLX} -c $< -o $@

# ---- Usual Commands ---- #

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME}

re				:	fclean
					$(MAKE)