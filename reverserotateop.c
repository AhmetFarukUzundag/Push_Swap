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

void    rra(t_node **a)
{
    t_node  *last;
    t_node  *temp;

    if (!a || !*a || !(*a)->next)
        return;

    temp = *a;

    while (temp->next->next)
        temp = temp->next;

    last = temp->next;
    temp->next = NULL;

    last->next = *a;
    *a = last;

    write(1, "rra\n", 3);
}
void    rrb(t_node **b)
{
    t_node  *last;
    t_node  *temp;

    if (!b || !*b || !(*b)->next)
        return;

    temp = *b;

    while (temp->next->next)
        temp = temp->next;

    last = temp->next;
    temp->next = NULL;

    last->next = *b;
    *b = last;

    write(1, "rrb\n", 3);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 3);
}
