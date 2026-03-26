/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 08:22:06 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/26 15:44:26 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(t_stack **a, int pos, t_bench *bench, t_config *cfg)
{
	int	size;

	size = stack_size(*a);
	if (pos < size / 2)
	{
		while (pos--)
			ra(a, bench, cfg);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			rra(a, bench, cfg);
	}
}

int	find_nearest_chunk(t_stack *a, int range_max)
{
	int		i;
	int		size;
	t_stack	*tmp;

	i = 0;
	size = stack_size(a);
	tmp = a;
	while (tmp)
	{
		if (tmp->index <= range_max)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (size);
}

static void	push_chunks(t_stack **a, t_stack **b, t_bench *bench, t_config *cfg)
{
	int	range_max;
	int	pushed;
	int	pos;

	range_max = cfg->chunk_size;
	pushed = 0;
	while (*a)
	{
		pos = find_nearest_chunk(*a, range_max);
		rotate_to_top(a, pos, bench, cfg);
		pb(a, b, bench, cfg);
		pushed++;
		if ((*b)->index < range_max - (cfg->chunk_size / 2))
			rb(b, bench, cfg);
		if (pushed == cfg->chunk_size)
		{
			range_max += cfg->chunk_size;
			pushed = 0;
		}
	}
}

void	medium_sort(t_stack **a, t_stack **b, t_bench *bench, t_config *cfg)
{
	int	size;
	int	chunk_count;

	size = stack_size(*a);
	if (size == 3)
		return (sort_three(a, bench, cfg));
	else if (size == 5)
		return (sort_five(a, b, bench, cfg));
	if (size == 3 && cfg->strategy != STRAT_MEDIUM)
		sort_three(a, bench, cfg);
	index_compression(a, size);
	if (size <= 100)
		chunk_count = 5;
	else
		chunk_count = 11;
	cfg->chunk_size = size / chunk_count;
	push_chunks(a, b, bench, cfg);
	push_back_to_a(a, b, bench, cfg);
}
