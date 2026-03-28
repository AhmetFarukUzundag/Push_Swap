/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:05:08 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/24 13:49:17 by auzundag         ###   ########.fr       */
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

static int	over_limit(long num, long limit, char c)
{
	return (num > (limit - (c - '0')) / 10);
}

static int	parse_prefix(const char *str, int *i, int *sign)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	return (ft_isdigit(str[*i]));
}

long	ft_atol(const char *str, int *error)
{
	int		i;
	long	num;
	int		sign;
	long	limit;

	i = 0;
	num = 0;
	sign = 1;
	*error = 0;
	if (!parse_prefix(str, &i, &sign))
		return (*error = 1, 0);
	limit = 2147483647L + (sign == -1);
	while (ft_isdigit(str[i]))
	{
		if (over_limit(num, limit, str[i]))
			return (*error = 1, 0);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (*error = 1, 0);
	return (num * sign);
}
