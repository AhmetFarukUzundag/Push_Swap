/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:50:18 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/24 13:53:50 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, t_bench *bench, int print_on)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
	{
		return ;
	}
	first = *a;
	*a = first->next;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (print_on)
		write(1, "ra\n", 3);
	if (bench)
	{
		bench->ra++;
		bench->total++;
	}
}

void	rb(t_stack **b, t_bench *bench, int print_on)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
	{
		return ;
	}
	first = *b;
	*b = first->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (print_on)
		write(1, "rb\n", 3);
	if (bench)
	{
		bench->rb++;
		bench->total++;
	}
}

void	rr(t_stack **a, t_stack **b, t_bench *bench, int print_on)
{
	ra(a, bench, print_on);
	rb(b, bench, print_on);
	if (print_on)
		write(1, "rr\n", 3);
	if (bench)
	{
		bench->rr++;
		bench->total++;
	}
}
