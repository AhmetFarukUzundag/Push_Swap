/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:59:16 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/11 15:26:30 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	addStack(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

static int	checkDup(t_stack *stack_a, int value)
{
	while (stack_a)
	{
		if (stack_a->data == value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	char	**tokens;
	int		i;
	int		value;
	int		error;

	a = NULL;
	error = 0;
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i++], ' ');
		if (!tokens || !*tokens)
			return (write(1, "error\n", 6), 0);
		while (*tokens)
		{
			value = ft_atol(*tokens, &error);
			if (error || checkDup(a, value))
				return (write(1, "error\n", 6), 0);
			addStack(&a, newNode(value));
			tokens++;
		}
	}
}

// argc = 4

// argv[0] = "./push_swap"
// argv[1] = "3"
// argv[2] = "2"
// argv[3] = "1"

// Edge Caseler

// boş input
// ./push_swap ""
// sadece boşluk
// ./push_swap "     "
// invalid karakter
// ./push_swap 1 2 a
// mixed
// ./push_swap 1 "2 a"
// duplicate
// ./push_swap 1 2 2
// int overflow
// ./push_swap 999999999999999
// sign hatası
// ./push_swap --
// ./push_swap +-

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
