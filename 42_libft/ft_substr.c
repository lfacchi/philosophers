/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lucdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:59:17 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/05/03 21:35:15 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_string;
	unsigned int	i;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (s == NULL)
		return (NULL);
	i = 0;
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new_string = malloc((sizeof(char) * len) + 1);
	if (new_string == NULL)
		return (NULL);
	while (i < len)
	{
		new_string[i] = s[start];
		start++;
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
