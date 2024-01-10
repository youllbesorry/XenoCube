/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xenocube.h                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:16:54 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/08 19:16:54 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef XENOCUBE_H
# define XENOCUBE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "minilibx-linux/mlx.h"
# include "src/type/type.h"
# include "src/utils/Libft/headers/libft.h"
# include "src/utils/Libft/headers/get_next_line.h"
# include "src/type/enum.h"
# include "src/utils/garbage_collector/garbage.h"
# include "src/core/core.h"
# include "src/parsing/parsing.h"

int		main(int argc, char **argv);

#endif
