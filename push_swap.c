/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:59:16 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/10 15:26:11 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// static int	is_number(char *argv)
// {
// 	// if sign varsa geç
// 	// geri kalan her şey digit olmalı
// }

// static t_stack	*parse_input(int argc, char **argv)
// {
// }

static t_stack	*newNode(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b;
	int		i;
	char	**tokens;
	int		j;
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;
	t_stack	*temp;

	if (!argv)
		write(1, "error\n", 6);
	if (argc < 2)
		return (0);
	i = 1;
	j = 0;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		j = 0;
		while (tokens[j])
		{
			// printf("%s\n", tokens[j]);
			j++;
		}
		i++;
	}
	node1 = newNode(1);
	node2 = newNode(2);
	node3 = newNode(3);
	node1->next = node2;
	node2->next = node3;
	printf("Before\n");
	temp = node1;
	while (temp)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	rra(&node1);
	printf("After\n");
	while (node1)
	{
		printf("%d\n", node1->data);
		node1 = node1->next;
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

// edge caseler
// 4a2
// --42
// ++42
// ""
// 3 2 1 3 (duplicate)

// push_swap programı. Programınız çalışma zamanında bir strateji seçebilmelidir
// Giriş yapılandırması üzerinde

// argv
// ↓
// split
// ↓
// tokens[]
