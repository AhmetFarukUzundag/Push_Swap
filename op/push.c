/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:50:28 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/23 19:21:51 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **a, t_stack **b, t_bench *bench, int print_on)
{
	t_stack	*temp;

	if (!a || !*a || !b)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (print_on)
		write(1, "pb\n", 3);
	if (bench)
		{
			bench->pb++;
			bench->total++;
		}
}

void	pa(t_stack **a, t_stack **b, t_bench *bench, int print_on)
{
	t_stack	*temp;

	if (!a || !b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	if (print_on)
		write(1, "pa\n", 3);
		if (bench)
		{
			bench->pa++;
			bench->total++
		}
}
