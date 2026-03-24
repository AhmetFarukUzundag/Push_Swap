/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one_three_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 21:59:38 by haydinog          #+#    #+#             */
/*   Updated: 2026/03/24 13:53:20 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a, t_bench *bench, int print_on)
{
	if ((*a)->data > (*a)->next->data)
		sa(a, bench, print_on);
}

void	sort_three(t_stack **a, t_bench *bench, int print_on)
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
		ra(a, bench, print_on);
	else if (first > second && second > third && first > third)
	{
		sa(a, bench, print_on);
		rra(a, bench, print_on);
	}
	else if (first < second && second > third && first > third)
		rra(a, bench, print_on);
	else if (first < second && second > third && first < third)
	{
		sa(a, bench, print_on);
		ra(a, bench, print_on);
	}
	else if (first > second && second < third && first < third)
		sa(a, bench, print_on);
}
