/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotateop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:50:23 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/10 08:46:36 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

// Son node başa gelir.
void	rra(t_node **a)
{
	t_node	*current;
	t_node	*last;
	t_node	*prev;

	if (!a || !*a || !(*a)->next)
		return ;
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
	write(1, "rra\n", 4);
}

void	rra(t_node **b)
{
	t_node	*current;
	t_node	*last;
	t_node	*prev;

	if (!b || !*b || !(*b)->next)
		return ;
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
	write(1, "rra\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
