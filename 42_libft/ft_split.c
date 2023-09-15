/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lucdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:12:46 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/05/03 21:17:16 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	count_word(const char *s, char c)
{
	unsigned int	i;
	unsigned int	on_word;
	unsigned int	nw;

	i = 0;
	on_word = 0;
	nw = 0;
	while (s[i])
	{
		if (s[i] != c && on_word == 0)
		{
			on_word = 1;
			nw++;
		}
		else if (s[i] == c)
			on_word = 0;
		i++;
	}
	return (nw);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	e_word;
	unsigned int	index;
	char			**array;

	i = 0;
	e_word = 0;
	index = 0;
	array = ft_calloc((count_word(s, c) + 1), sizeof(char *));
	while (s[i])
	{
		if (s[i] != c)
			e_word++;
		if ((s[i] == c && e_word > 0))
		{
			array[index] = ft_substr(&s[i - e_word], 0, e_word);
			index++;
			e_word = 0;
		}
		i++;
	}
	if (e_word)
		array[index] = ft_substr(&s[i - e_word], 0, e_word);
	return (array);
}
