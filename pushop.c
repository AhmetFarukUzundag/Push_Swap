/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:50:28 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/10 08:53:36 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void	pb(t_node **a, t_node **b, int print_on)
{
	t_node	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (print_on)
		write(1, "pb\n", 3);
}

void	pa(t_node **a, t_node **b, int print_on)
{
	t_node	*temp;

	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	if (print_on)
		write(1, "pa\n", 3);
}
