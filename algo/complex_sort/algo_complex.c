/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:27:54 by haydinog          #+#    #+#             */
/*   Updated: 2026/03/23 22:18:07 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_big_index(t_stack *a) // en büyük indexi buluyorumh
{
	int max_index;
	t_stack *tmp;

	if (!a)
		return(0);
	tmp = a;
	max_index = tmp->index;
	while(tmp)
	{
		if(max_index < tmp->index)
			max_index = tmp->index;
		tmp = tmp->next; 
	}
	return(max_index);
}

static int how_many_bits(t_stack **a) // en büyük indexin kaç bit oldugunu buluyorumh
{
	int max;
	int bits;

	bits = 0;
	max = find_big_index(*a);

	while (max != 0)
	{
	  max = max >> 1;
	  bits++;
	}
	return(bits);
}

void radix_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int		size_a;
	int		max_bits;
	int     i;
	int     j;
	
	max_bits = how_many_bits(a);
	size_a = stack_size(*a);
	i = 0;
	while(i < max_bits)
	{
		j = 0;
		while(j < size_a)
		{
			if (((*a)->index >> i) & 1)
				ra(a,bench);
			else
				pb(a,b,bench,1);
			j++;
		}
		while(*b)
			pa(a,b,bench,1);
		i++;
	}
}
