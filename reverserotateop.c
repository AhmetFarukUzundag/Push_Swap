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
void	rra(t_node **a)
{
    t_node  *last;
    t_node  *prev;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a; // head
	while (last->next) 
	{
		prev = last; // 3
		last = last->next; // 4
	}
	prev->next = NULL; // 3 -> NULL
	last->next = *a;	// 4 -> 1
	*a = last;
	write(1, "rra\n", 3);
}

void	rrb(t_node **b)
{
    t_node  *last;
    t_node  *prev;

	if (!b || !*b || !(*b)->next)
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
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
