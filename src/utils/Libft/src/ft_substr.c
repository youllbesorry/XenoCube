/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:52:44 by bfaure            #+#    #+#             */
/*   Updated: 2022/11/17 21:52:44 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static char	*ft_cpy(char *dst, const char *src, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	while ((src[start] != '\0' && !ft_isspace(src[start])) && i < len)
	{
		dst[i] = src[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(t_cub_context *cubx, char const *s,
	unsigned int start, size_t len)
{
	char	*dest;

	if (!s)
		return (NULL);
	if (start + 1 == len)
		return (ft_strdup(cubx, ""));
	if (start > ft_strlen(s))
		return (ft_strdup(cubx, ""));
	if (len < ft_strlen(&s[start]))
		dest = cubx->gc->malloc(cubx, sizeof(char) * (len + 1), false);
	else
		dest = cubx->gc->malloc(cubx, sizeof(char)
				* (ft_strlen(&s[start]) + 1), false);
	if (!dest)
		return (NULL);
	return (ft_cpy(dest, s, start, len));
}
