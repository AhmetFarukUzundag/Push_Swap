/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:50:16 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/26 15:45:55 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stack *a)
{
	int	min;

	min = a->data;
	while (a)
	{
		if (a->data < min)
			min = a->data;
		a = a->next;
	}
	return (min);
}

static int	min_position_simple(t_stack *a)
{
	int	min;
	int	position;
	int	i;

	i = 0;
	position = 0;
	min = find_min(a);
	while (a)
	{
		if (a->data == min)
		{
			position = i;
			break ;
		}
		i++;
		a = a->next;
	}
	return (position);
}

static void	min_to_top_simple(t_stack **a, t_bench *bench, t_config *cfg)
{
	int	position;
	int	move_size;
	int	reverse_move;

	move_size = stack_size(*a) / 2;
	position = min_position_simple(*a);
	if (position <= move_size)
	{
		while (position > 0)
		{
			ra(a, bench, cfg);
			position--;
		}
	}
	else
	{
		reverse_move = stack_size(*a) - position;
		while (reverse_move > 0)
		{
			rra(a, bench, cfg);
			reverse_move--;
		}
	}
}

void	simple_sort(t_stack **a, t_stack **b, t_bench *bench, t_config *cfg)
{
	int	size;

	size = stack_size(*a);
	while (size > 0)
	{
		if (size == 3 && cfg->strategy != STRAT_SIMPLE)
		{
			sort_three(a, bench, cfg);
			break ;
		}
		if (size == 2 && cfg->strategy != STRAT_SIMPLE)
		{
			sort_two(a, bench, cfg);
			break ;
		}
		else
		{
			min_to_top_simple(a, bench, cfg);
			pb(a, b, bench, cfg);
			size--;
		}
	}
	while (*b)
		pa(a, b, bench, cfg);
}
