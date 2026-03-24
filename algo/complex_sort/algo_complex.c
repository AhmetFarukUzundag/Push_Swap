/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:27:54 by haydinog          #+#    #+#             */
/*   Updated: 2026/03/24 13:50:13 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_big_index(t_stack *a)
{
	int		max_index;
	t_stack	*tmp;

	if (!a)
		return (0);
	tmp = a;
	max_index = tmp->index;
	while (tmp)
	{
		if (max_index < tmp->index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	return (max_index);
}

static int	how_many_bits(t_stack **a)
{
	int	max;
	int	bits;

	bits = 0;
	max = find_big_index(*a);
	while (max != 0)
	{
		max = max >> 1;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b, t_bench *bench, int print_on)
{
	int	size_a;
	int	max_bits;
	int	i;
	int	j;

	max_bits = how_many_bits(a);
	size_a = stack_size(*a);
	if (size_a == 3)
		return (sort_three(a, bench, print_on));
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size_a)
		{
			if (((*a)->index >> i) & 1)
				ra(a, bench, print_on);
			else
				pb(a, b, bench, print_on);
			j++;
		}
		while (*b)
			pa(a, b, bench, print_on);
		i++;
	}
}
