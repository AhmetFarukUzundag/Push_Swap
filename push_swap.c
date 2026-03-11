/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:59:16 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/11 12:30:12 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// static t_stack	*newNode(int data)
// {
// 	t_stack	*node;

// 	node = malloc(sizeof(t_stack));
// 	if (!node)
// 		return (NULL);
// 	node->data = data;
// 	node->next = NULL;
// 	return (node);
// }

static int	isNumber(char *str)
{
}

static int	parseNumber(char *token)
{
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**tokens;

	if (!argv)
		write(1, "error\n", 6);
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i++], ' ');
		j = 0;
		while (tokens[j])
		{
			parseNumber(tokens[j]);
			j++;
		}
		i++;
	}
}

// argc = 4

// argv[0] = "./push_swap"
// argv[1] = "3"
// argv[2] = "2"
// argv[3] = "1"

// edge caseler
// 4a2
// --42
// ++42
// ""
// 3 2 1 3 (duplicate)

// push_swap programı. Programınız çalışma zamanında bir strateji seçebilmelidir
// Giriş yapılandırması üzerinde

// main
//  ↓
// parse_args
//  ↓
// argv[i]
//  ↓
// split
//  ↓
// tokens[j]
//  ↓
// validate_number
//  ↓
// ft_atol
//  ↓
// check_duplicate
//  ↓
// stack_add_back
