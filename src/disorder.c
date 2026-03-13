/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:47:28 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/10 08:47:31 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
    
double compute_disorder(t_stack *a)
{
    t_stack *i;
    t_stack *j;
    double mistakes = 0;
    double total_pairs = 0;

    if (!a || a->next)
        return (0.0);

    i = a;
    while (i)
    {
        j = i->next;
        while (j)
        {
            total_pairs++;

            if (i->data > j->data)
                mistakes++;

            j = j->next;
        }
        i = i->next;
    }

    return (mistakes / total_pairs);
}
