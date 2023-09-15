/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lucdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:53:00 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/05/03 21:21:56 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new_string;

	new_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	i = 0;
	j = ft_strlen(s1);
	if (new_string == NULL || (s1 == NULL || s2 == NULL))
		return (NULL);
	while (s1[i])
	{
		new_string[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		new_string[j] = s2[i];
		j++;
		i++;
	}
	new_string[j] = '\0';
	return (new_string);
}
