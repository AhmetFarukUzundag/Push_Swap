/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotateop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:50:23 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/07 16:36:28 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

// Son node başa gelir.
void    rra(t_node **a)
{
    t_node *current;
    t_node *last;
    t_node *prev;

    if (!a || !*a || !(*a)->next)
        return;

    current = *a;
    prev = NULL;

    while (current->next)
    {
        if (!current->next->next)
            prev = current;
        last = current->next;
        current = current->next;
    }

    prev->next = NULL;
    last->next = *a;
    *a = last;
    write(1, "rra\n", 3);
}

void    rra(t_node **b)
{
    t_node *current;
    t_node *last;
    t_node *prev;

    if (!b || !*b || !(*b)->next)
        return;

    current = *b;
    prev = NULL;

    while (current->next)
    {
        if (!current->next->next)
            prev = current;
        last = current->next;
        current = current->next;
    }

    prev->next = NULL;
    last->next = *b;
    *b = last;
    write(1, "rra\n", 3);
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 3);
}
