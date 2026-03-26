/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one_three_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 21:59:38 by haydinog          #+#    #+#             */
/*   Updated: 2026/03/26 15:34:40 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a, t_bench *bench, t_config *cfg)
{
	if ((*a)->data > (*a)->next->data)
		sa(a, bench, cfg);
}

void	sort_three(t_stack **a, t_bench *bench, t_config *cfg)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->data;
	second = (*a)->next->data;
	third = (*a)->next->next->data;
	if (first < second && second < third && first < third)
		return ;
	else if (first > second && second < third && first > third)
		ra(a, bench, cfg);
	else if (first > second && second > third && first > third)
	{
		sa(a, bench, cfg);
		rra(a, bench, cfg);
	}
	else if (first < second && second > third && first > third)
		rra(a, bench, cfg);
	else if (first < second && second > third && first < third)
	{
		sa(a, bench, cfg);
		ra(a, bench, cfg);
	}
	else if (first > second && second < third && first < third)
		sa(a, bench, cfg);
}

void	sort_five(t_stack **a, t_stack **b, t_bench *bench, t_config *cfg)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		min_to_top(a, bench, cfg);
		pb(a, b, bench, cfg);
		i++;
	}
	sort_three(a, bench, cfg);
	pa(a, b, bench, cfg);
	pa(a, b, bench, cfg);
}

int	min_position(t_stack *a)
{
	int	min_val;
	int	pos;
	int	min_pos;

	if (!a)
		return (-1);
	min_val = a->data;
	min_pos = 0;
	pos = 0;
	while (a)
	{
		if (a->data < min_val)
		{
			min_val = a->data;
			min_pos = pos;
		}
		a = a->next;
		pos++;
	}
	return (min_pos);
}

void	min_to_top(t_stack **a, t_bench *bench, t_config *cfg)
{
	int	pos;
	int	size;

	pos = min_position(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(a, bench, cfg);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(a, bench, cfg);
			pos++;
		}
	}
}
