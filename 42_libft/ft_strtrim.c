/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lucdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:36:46 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/05/03 21:32:55 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_verify(char s, const char *test)
{
	int	i;

	i = 0;
	while (test[i])
	{
		if (s == test[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	final;
	size_t	i;
	char	*str_final;

	if (set == NULL || s1 == NULL)
		return (NULL);
	i = 0;
	final = ft_strlen(s1);
	while (ft_verify(s1[i], set) == 1)
		i++;
	while (ft_verify(s1[final - 1], set) == 1)
		final--;
	if (i > final)
		str_final = ft_substr(s1, i, (i));
	else
		str_final = ft_substr(s1, i, (final - i));
	return (str_final);
}
