/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:50:18 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/23 22:07:03 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// head en sona gider
void ra(t_stack **a, t_bench *bench)
{
	t_stack *first;
	t_stack *last;

	if (!a || !*a || !(*a)->next)
	{
		return;
	}

	first = *a;
	*a = first->next;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
		if (bench)
	{
		bench->ra++;
		bench->total++;
	}
}

void rb(t_stack **b, t_bench *bench)
{
	t_stack *first;
	t_stack *last;

	if (!b || !*b || !(*b)->next)
	{
		return;
	}

	first = *b;
	*b = first->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
		if (bench)
	{
		bench->rb++;
		bench->total++;
	}
}

void rr(t_stack **a, t_stack **b, t_bench *bench)
{
	ra(a,bench);
	rb(b,bench);
	write(1, "rr\n", 3);
		if (bench)
	{
		bench->rr++;
		bench->total++;
	}
}
