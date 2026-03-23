/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:50:16 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/23 23:52:36 by haydinog         ###   ########.fr       */
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

static void	min_to_top(t_stack **a, t_bench *bench, int print_on)
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
			ra(a, bench,print_on);
			position--;
		}
	}
	else
	{
		reverse_move = stack_size(*a) - position;
		while (reverse_move > 0)
		{
			rra(a, bench,print_on);
			reverse_move--;
		}
	}
}

void	simple_sort(t_stack **a, t_stack **b, t_bench *bench, int print_on)
{
	int	size;

	size = stack_size(*a);
	while (size > 0)
	{
		if (size == 3)
		{
			sort_three(a,bench,print_on);
			break ;
		}
		if (size == 2)
		{
			sort_two(a,bench,print_on);
			break ;
		}
		else
		{
			min_to_top(a,bench,print_on);
			pb(a, b,bench, print_on);
			size--;
		}
	}
	while (*b)
		pa(a, b, bench, print_on);
}
