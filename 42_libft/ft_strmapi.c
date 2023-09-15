/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lucdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:36:15 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/05/03 21:27:36 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new_string;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	new_string = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	while (s[i])
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	return (new_string);
}
