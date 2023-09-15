/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lucdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:52:21 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/05/03 21:24:18 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
size == 0 >> return len src
size < len(dest)>> return len(src) + size 

 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	i;

	len_dst = ft_strlen(dst);
	if (dst == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	if (size <= len_dst)
		return (ft_strlen(src) + size);
	else
	{
		i = 0;
		while (i < (size - len_dst) - 1 && src[i])
		{
			dst[i + len_dst] = src[i];
			i++;
		}
	}
	dst[ft_strlen(dst)] = '\0';
	len_dst = ft_strlen(dst);
	return (len_dst + ft_strlen(&src[i]));
}
