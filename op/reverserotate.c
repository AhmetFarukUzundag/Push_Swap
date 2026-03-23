/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:50:23 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/23 23:50:40 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Son node başa gelir.
void	rra(t_stack **a, t_bench *bench, int print_on)
{
	t_stack	*current;
	t_stack	*last;
	t_stack	*prev;

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
	if (print_on)
		write(1, "rra\n", 3);
	if (bench)
	{
		bench->rra++;
		bench->total++;
	}
}

void	rrb(t_stack **b, t_bench *bench, int print_on)
{
	t_stack	*current;
	t_stack	*last;
	t_stack	*prev;

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
	if (print_on)
		write(1, "rrb\n", 3);
	if (bench)
	{
		bench->rrb++;
		bench->total++;
	}
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench, int print_on)
{
	rra(a, bench,print_on);
	rrb(b, bench,print_on);
if (print_on)
	write(1, "rrr\n", 3);
if (bench)
{
	bench->rrr++;
	bench->total++;
}
}
