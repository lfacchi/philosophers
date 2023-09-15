/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lucdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:36:15 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/05/03 20:51:18 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_convert_number(int n)
{
	char	c;

	c = n + 48;
	return (c);
}

int	ft_ndigit(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str_num;
	int		len_num;
	int		sign;

	sign = 0;
	len_num = ft_ndigit(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	str_num = ft_calloc(len_num + 1 + sign, sizeof(char));
	str_num[0] = '-';
	while (len_num > 0)
	{
		str_num[len_num - 1 + sign] = ft_convert_number(n % 10);
		n = n / 10;
		len_num--;
	}
	return (str_num);
}
