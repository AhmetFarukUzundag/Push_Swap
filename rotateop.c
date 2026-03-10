/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:50:18 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/10 09:12:16 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// head en sona gider
void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

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

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

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

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
