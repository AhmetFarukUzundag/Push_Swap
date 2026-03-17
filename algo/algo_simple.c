/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:50:16 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/17 14:37:07 by auzundag         ###   ########.fr       */
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

static int	min_position(t_stack *a)
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

static void	min_to_top(t_stack **a)
{
	int	position;
	int	move_size;
	int	reverse_move;

	move_size = stack_size(*a) / 2;
	position = min_position(*a);
	if (position <= move_size)
	{
		while (position > 0)
		{
			ra(a);
			position--;
		}
	}
	else
	{
		reverse_move = stack_size(*a) - position;
		while (reverse_move > 0)
		{
			rra(a);
			reverse_move--;
		}
	}
}

void	simple_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	while (size > 0)
	{
		if (size == 3)
		{
			sort_three(a);
			break ;
		}
		if (size == 2)
		{
			sort_two(a);
			break ;
		}
		else
		{
			min_to_top(a);
			pb(a, b, 1);
			size--;
		}
	}
	while (*b)
		pa(a, b, 1);
}
