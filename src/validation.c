#include "philo.h"

void	check_num(char **arr)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (arr[i])
	{
		j = 0;
		if (arr[i][j] == '-')
			j++;
		while (arr[i][j])
		{
			if (!ft_isdigit(arr[i][j]))
			{
				write(2, "Error\n", 6);
				exit(2);
			}
			j++;
		}
		i++;
	}
}