/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:27:04 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/10 08:55:24 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_dup(t_stack *stack_a, int value)
{
    while (stack_a)
    {
        if (stack_a->data == value)
            return (1);
        stack_a = stack_a->next;
    }
    return (0);
}

static void free_tokens(char **tokens)
{
    int i;

    if (!tokens)
        return;
    i = 0;
    while (tokens[i])
    {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

int parser_arguments(int argc, char **argv, t_stack **a)
{
    char **tokens;
    char **cur;
    int i;
    int value;
    int error;

    *a = NULL;
    i = 1;
    while (i < argc)
    {
        tokens = ft_split(argv[i++], ' ');
        if (!tokens || !*tokens)
            return (free_tokens(tokens), free_stack(a),
                    write(1, "error\n", 6), 0);
        cur = tokens;
        while (*cur)
        {
            value = ft_atol(*cur, &error);
            if (error || check_dup(*a, value))
                return (free_tokens(tokens), free_stack(a),
                        write(1, "error\n", 6), 0);
            add_stack_back(a, new_node(value));
            cur++;
        }

        free_tokens(tokens);
    }

    return (1); // success
}
