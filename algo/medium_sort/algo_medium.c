/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 08:22:06 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/18 10:30:16 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    medium_sort(t_stack **a, t_stack **b)
{
    int size;
    int chunk_count;
    int chunk_size;
    int range_max;
    int pushed;

    index_compression(a);

    size = stack_size(*a); // 50

    if (size <= 100)
        chunk_count = 5;
    else
        chunk_count = 11;

    chunk_size = size / chunk_count; // 10
    range_max = chunk_size;          // 10
    pushed = 0;

    while (*a)
    {
        if ((*a)->index <= range_max) // 7->index = 4 | r_max = 10 | true
        {
            pb(a, b, 1);
            pushed++;

            if ((*b)->index < range_max - (chunk_size / 2)) // 4 < 4
                rb(b);

            if (pushed == chunk_size)
            {
                range_max += chunk_size;
                pushed = 0;
            }
        }
        else
            ra(a);
    }

    /* B → A geri toplama */
    while (*b)
    {
        int max_pos = find_max_position(*b);

        if (max_pos <= stack_size(*b) / 2)
        {
            while (max_pos--)
                rb(b);
        }
        else
        {
            max_pos = stack_size(*b) - max_pos;
            while (max_pos--)
                rrb(b);
        }
        pa(a, b, 1);
    }
}
