/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:50:12 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/23 19:25:29 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;

}

void	sa(t_stack **a, t_bench *bench)
{
	swap(a);
	write(1, "sa\n", 3);
		if (bench)
	{
		bench->sa++;
		bench->total++;
	}
}

void	sb(t_stack **b, t_bench *bench)
{
	swap(b);
	write(1, "sb\n", 3);
		if (bench)
	{
		bench->sb++;
		bench->total++;
	}
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
		if (bench)
	{
		bench->ss++;
		bench->total++;
	}
}
