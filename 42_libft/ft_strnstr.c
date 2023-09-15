/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lucdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 01:46:28 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/05/03 21:30:13 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (big == NULL || little == NULL || len < ft_strlen(little))
		return (NULL);
	if (!(little[i]))
		return ((char *)big);
	while (big[i] && (i < len))
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && (i + j) < len)
		{
			if (!(little[j + 1]))
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (0);
}
