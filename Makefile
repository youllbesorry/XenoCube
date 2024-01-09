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

DIR_SRCS	=	src/

DIR_UTILS	=	${DIR_SRCS}utils/

DIR_GARBAGE	=	${DIR_UTILS}garbage_collector/

DIR_CORE	=	${DIR_SRCS}core/

DIR_PARS	= 	${DIR_SRCS}parsing/

DIR_MLX		=	minilibx-linux/

DIR_LIBFT	=	${DIR_UTILS}Libft/

LIBFT_A = $(DIR_LIBFT)$(LIBFT)

MLXLIB_A = $(DIR_MLX)$(LIBMLX)

# ---- Files ---- #

SRCS			=	main.c \
					${DIR_GARBAGE}gc_fonc.c \
					${DIR_GARBAGE}gc_init.c \
					${DIR_CORE}init_ctx.c \


OBJS = ${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

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
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_LIBFT} -L${DIR_MLX} -lm

# ---- Compiled Rules ---- #

-include ${DEPS}

${DIR_OBJS}%.o	:	%.c $(LIBFT_A) $(MLXLIB_A)
					$(MKDIR) $(shell dirname $@)
					${CC} ${CFLAGS}  -c $< -o $@ -I $(DIR_LIBFT) -I ${DIR_MLX} -Iminilibx -Ilibft

# ---- Usual Commands ---- #

fclean_lib		:
					make fclean -C ${DIR_LIBFT}
					make clean -C ${DIR_MLX}

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean fclean_lib
					${RM} ${NAME}

re				:	fclean
					$(MAKE)