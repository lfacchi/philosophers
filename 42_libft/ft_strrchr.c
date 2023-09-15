/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lucdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:28:44 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/05/03 21:31:01 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	if ((unsigned char)c == '\0')
		return ((char *)(s + i + 1));
	while (i >= 0)
	{
		if ((unsigned char)s[i] == (unsigned char) c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
