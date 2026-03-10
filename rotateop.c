/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:50:18 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/10 08:46:25 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

// head en sona gider
void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	first = *a;
	*a = first->next;
	last = *a;
	while (last->next)     // first->next var mı
		last = last->next; // sonu tutuyor
	last->next = first;
	first->next = NULL;
	// head -> son
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	first = *b;
	*b = first->next;
	last = *b;
	while (last->next)     // first->next var mı
		last = last->next; // sonu tutuyor
	last->next = first;
	first->next = NULL;
	// head -> son
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
