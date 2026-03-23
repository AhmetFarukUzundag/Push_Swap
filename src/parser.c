/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:27:04 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/17 15:53:38 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_dup(t_stack *stack_a, int value)
{
	while (stack_a)
	{
		if (stack_a->data == value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

static void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static int	parse_tokens(char **tokens, t_stack **a)
{
	char	**cur;
	int		value;
	int		error;

	cur = tokens;
	while (*cur)
	{
		value = ft_atol(*cur, &error);
		if (error || check_dup(*a, value))
			return (0);
		add_stack_back(a, new_node(value));
		cur++;
	}
	return (1);
}

int	parser_arguments(int argc, char **argv, t_stack **a)
{
	char	**tokens;
	int		i;

	*a = NULL;
	i = 0;
	while (i < argc)
	{
		tokens = ft_split(argv[i++], ' ');
		if (!tokens || !*tokens || !parse_tokens(tokens, a))
			return (free_tokens(tokens), free_stack(a), write(2, "Error\n", 6),
				0);
		free_tokens(tokens);
	}
	return (1);
}
