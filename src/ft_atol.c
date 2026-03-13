/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:05:08 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/11 15:12:00 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

long	ft_atol(const char *str, int *error)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	*error = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
	{
		*error = 1;
		return (0);
	}
	while (ft_isdigit(str[i]) && !*error)
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if ((sign == 1 && num > 2147483647L)
		|| (sign == -1 && num > 2147483648L))
		*error = 1;
	if (str[i] != '\0')
		*error = 1;
	if (*error)
		return (0);
	return (num * sign);
}
