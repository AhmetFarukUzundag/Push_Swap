/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:59:16 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/10 11:55:16 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *str)
{
	// if sign varsa geç
	// geri kalan her şey digit olmalı
}

static t_stack	*parse_input(int argc, char **argv)
{
}

static int	flag_check(void)
{
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		ft_split(argv[i], ' ');
		i++;
	}
}

// argc = 4

// argv[0] = "./push_swap"
// argv[1] = "3"
// argv[2] = "2"
// argv[3] = "1"

// argv
//  ↓
// for each argv[i]
//  ↓
// split
//  ↓
// numbers list
//  ↓
// validate
//  ↓
// atoi
//  ↓
// stack