/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lucdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:06:31 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/05/03 21:00:15 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;
	unsigned char	*temp2;

	if (dest == NULL || src == NULL)
		return (NULL);
	if (src < dest)
	{
		temp = (unsigned char *)src;
		temp2 = (unsigned char *)dest;
		while (n--)
			temp2[n] = temp[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
