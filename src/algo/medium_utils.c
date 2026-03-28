/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:43:05 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/25 16:09:19 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_position(t_stack *stack)
{
	t_stack	*tmp;
	int		max_index;
	int		max_pos;
	int		pos;

	max_index = -1;
	max_pos = 0;
	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > max_index)
		{
			max_index = tmp->index;
			max_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (max_pos);
}

void	push_back_to_a(t_stack **a, t_stack **b, t_bench *bench, t_config *cfg)
{
	int	max_pos;

	while (*b)
	{
		max_pos = find_max_position(*b);
		if (max_pos <= stack_size(*b) / 2)
		{
			while (max_pos--)
				rb(b, bench, cfg);
		}
		else
		{
			max_pos = stack_size(*b) - max_pos;
			while (max_pos--)
				rrb(b, bench, cfg);
		}
		pa(a, b, bench, cfg);
	}
}
