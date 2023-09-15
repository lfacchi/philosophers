/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lucdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:28:14 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/05/03 20:57:14 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{	
	size_t			i;
	size_t			diff;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	diff = 0;
	if ((s1 == NULL || s2 == NULL) || (n == 0))
		return (0);
	while (i < n)
	{
		diff = p1[i] - p2[i];
		if (p1[i] != p2[i])
			break ;
		i++;
	}
	return (diff);
}
