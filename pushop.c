/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:50:28 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/05 11:32:15 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void	pa(t_node **a, t_node **b, int print_on)
{
	t_node	*temp;

	temp = *a;
	*a = (*a)->next; // a'nın 2.
	temp->next = *b; // head'i b ye bagladım
	*b = temp;
	if (print_on)
		write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a)
{
	t_node	*temp;

	temp = *b;
	*b = (*b)->next; // a'nın 2.
	temp->next = *a; // head'i b ye bagladım
	*a = temp;
	write(1, "pb\n", 3);
}
			