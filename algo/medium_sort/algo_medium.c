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

// range belirle
// ↓
// range içindeki en yakın elemanı bul
// ↓
// oraya rotate et
// ↓
// pb
// ↓
// rb optimize
// ↓
// range büyüt

void rotate_to_top(t_stack **a, int pos)
{
    int size = stack_size(*a);

    if (pos < size / 2)
    {
        while (pos--)
            ra(a);
    }
    else
    {
        pos = size - pos;
        while (pos--)
            rra(a);
    }
}

// Bu fonksiyon stack'i tarar ilk bulduğu range elemanının return eder pozisyonunu return eder
int find_nearest_chunk(t_stack *a, int range_max)
{
    int i = 0;
    int size = stack_size(a);
    t_stack *tmp = a;

    while (tmp)
    {
        if (tmp->index <= range_max)
            return i;
        tmp = tmp->next;
        i++;
    }
    return size;
}

void push_chunks(t_stack **a, t_stack **b, int chunk_size)
{
    int range_max;
    int pushed;
    int pos;

    range_max = chunk_size;
    pushed = 0;

    while (*a)
    {
        pos = find_nearest_chunk(*a, range_max);

        rotate_to_top(a, pos);

        pb(a, b, 1);

        pushed++;

        if ((*b)->index < range_max - (chunk_size / 2))
            rb(b);

        if (pushed == chunk_size)
        {
            range_max += chunk_size;
            pushed = 0;
        }
    }
}

void push_back_to_a(t_stack **a, t_stack **b)
{
    int max_pos;

    while (*b)
    {
        max_pos = find_max_position(*b);

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

void medium_sort(t_stack **a, t_stack **b)
{
    int size;
    int chunk_count;
    int chunk_size;

    index_compression(a);

    size = stack_size(*a);

    if (size <= 100)
        chunk_count = 5;
    else
        chunk_count = 11;

    chunk_size = size / chunk_count;

    push_chunks(a, b, chunk_size);
    push_back_to_a(a, b);
}
