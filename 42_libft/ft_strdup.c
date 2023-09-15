/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lucdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 02:32:39 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/04/19 02:43:12 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*strdup;

	i = 0;
	if (s == NULL)
		return (NULL);
	strdup = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	while (s[i])
	{
		strdup[i] = s[i];
		i++;
	}
	strdup[i] = 0;
	return (strdup);
}
