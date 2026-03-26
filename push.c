/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:50:28 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/25 18:30:33 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **a, t_stack **b, t_bench *bench, t_config *cfg)
{
	t_stack	*temp;

	if (!a || !*a || !b)
		return ;
	(void)cfg;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
	if (bench)
	{
		bench->pb++;
		bench->total++;
	}
}

void	pa(t_stack **a, t_stack **b, t_bench *bench, t_config *cfg)
{
	t_stack	*temp;

	if (!a || !b || !*b)
		return ;
	(void)cfg;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
	if (bench)
	{
		bench->pa++;
		bench->total++;
	}
}
