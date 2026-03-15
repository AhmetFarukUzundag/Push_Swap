/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one_three_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 21:59:38 by haydinog          #+#    #+#             */
/*   Updated: 2026/03/15 22:27:10 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two(t_stack **a) // 2 1
{
    if ((*a)->data > (*a)->next->data)
        sa(a);
}

void sort_three(t_stack **a) // 3 lü sayılar olursa her ihtimali yazıp ona gore swapliyorum
{
    int first;
    int second;
    int third;

    first = (*a)->data;
    second = (*a)->next->data;
    third = (*a)->next->next->data;
    if (first < second && second < third && first < third) // 1 2 3
        return;
    else if (first > second && second < third && first > third) // 3 1 2
        ra(a);
    else if (first > second && second > third && first > third) // 3 2 1
    {
        sa(a);
        rra(a);
    }
    else if (first < second && second > third && first > third) // 2 3 1
        rra(a);
    else if (first < second && second > third && first < third) // 1 3 2
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first < third) // 2 1 3
        sa(a);
}
