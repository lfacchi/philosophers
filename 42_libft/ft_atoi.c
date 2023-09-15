/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lucdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 03:12:13 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/05/03 20:22:57 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ascii 9 -. 13  Tabulation
int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	sign = 0;
	if (nptr == NULL)
		return (0);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = 1;
		i++;
	}
	num = 0;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		num = (num * 10) + nptr[i] - 48;
		i++;
	}
	if (sign == 1)
		num = -num;
	return (num);
}
