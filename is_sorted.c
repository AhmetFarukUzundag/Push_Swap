/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:06:41 by haydinog          #+#    #+#             */
/*   Updated: 2026/03/07 16:08:54 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int is_sorted(t_node *a)
{
    while (a && a->next)
    {
        if (a->data > a->next->data)
            return(0);
        a = a->next;
    }
    return(1);
}
