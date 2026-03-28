/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:50:23 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/25 18:29:59 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, t_bench *bench, t_config *cfg)
{
	t_stack	*current;
	t_stack	*last;
	t_stack	*prev;

	if (!a || !*a || !(*a)->next)
		return ;
	(void)cfg;
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
	if (bench)
	{
		bench->rra++;
		bench->total++;
	}
}

void	rrb(t_stack **b, t_bench *bench, t_config *cfg)
{
	t_stack	*current;
	t_stack	*last;
	t_stack	*prev;

	if (!b || !*b || !(*b)->next)
		return ;
	(void)cfg;
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
	write(1, "rrb\n", 4);
	if (bench)
	{
		bench->rrb++;
		bench->total++;
	}
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench, t_config *cfg)
{
	rra(a, bench, cfg);
	rrb(b, bench, cfg);
	(void)cfg;
	if (bench)
	{
		bench->rrr++;
		bench->total++;
	}
	write(1, "rrr\n", 4);
}
