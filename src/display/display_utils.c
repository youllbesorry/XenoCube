/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:25:46 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/25 15:27:45 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->img_w || y < 0 || y >= img->img_h)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	char	*dst;
	if (x < 0 || x >= img->img_w || y < 0 || y >= img->img_h)
		return (0);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(int *)dst);
}

void	draw_line(t_img *img, t_vec p1, t_vec p2, int color)
{
	int	dx;
	int	dy;
	int	steps;
	int i;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	i = 0;
	put_pixel(img, p1.x, p1.y, color);
	while (i < steps)
	{
		p1.x += dx / steps;
		p1.y += dy / steps;
		put_pixel(img, p1.x, p1.y, color);
		i++;
	}
}