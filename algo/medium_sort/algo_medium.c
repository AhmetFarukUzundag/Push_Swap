/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 08:22:06 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/23 23:53:02 by haydinog         ###   ########.fr       */
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

static int find_max_position(t_stack *stack)
{
    int     max_index;
    int     max_pos;
    int     pos;
    t_stack *tmp;

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

void rotate_to_top(t_stack **a, int pos, t_bench *bench, int print_on)
{
    int size = stack_size(*a);

    if (pos < size / 2)
    {
        while (pos--)
            ra(a,bench,print_on);
    }
    else
    {
        pos = size - pos;
        while (pos--)
            rra(a,bench,print_on);
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

void push_chunks(t_stack **a, t_stack **b, int chunk_size, t_bench *bench, int print_on)
{
    int range_max;
    int pushed;
    int pos;

    range_max = chunk_size;
    pushed = 0;

    while (*a)
    {
        pos = find_nearest_chunk(*a, range_max);

        rotate_to_top(a, pos, bench, print_on);

        pb(a, b,bench,print_on);

        pushed++;

        if ((*b)->index < range_max - (chunk_size / 2))
            rb(b,bench,print_on);

        if (pushed == chunk_size)
        {
            range_max += chunk_size;
            pushed = 0;
        }
    }
}

void push_back_to_a(t_stack **a, t_stack **b, t_bench *bench, int print_on)
{
    int max_pos;

    while (*b)
    {
        max_pos = find_max_position(*b);

        if (max_pos <= stack_size(*b) / 2)
        {
            while (max_pos--)
                rb(b,bench,print_on);
        }
        else
        {
            max_pos = stack_size(*b) - max_pos;
            while (max_pos--)
                rrb(b,bench,print_on);
        }
        pa(a, b, bench, print_on);
    }
}

void medium_sort(t_stack **a, t_stack **b, t_bench *bench, int print_on)
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

    push_chunks(a, b, chunk_size, bench,print_on);
    push_back_to_a(a, b, bench,print_on);
}
