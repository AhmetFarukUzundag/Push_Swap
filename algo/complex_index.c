/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.com.tr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-17 11:57:33 by haydinog          #+#    #+#             */
/*   Updated: 2026-03-17 11:57:33 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_index(t_stack *a) // indexlerini -1 veriyorum
{
	while(a)
    {
        a->index = -1;
        a = a->next;
    }
}

static t_stack *find_min(t_stack *a) //min değer atama
{
    t_stack *min;
    t_stack *tmp;

    min = NULL;
    tmp = a;
    while (tmp)
    {
        if(tmp->index == -1)
        {
            if(min == NULL || tmp->data < min->data)
                min = tmp;
        }
        tmp = tmp->next;
    }
    return (min);
}

void normalize(t_stack *a) // min buluyorum index veriyorum sonraki mini buluyorum sonraki indexi veriyorum
{
  t_stack *min;
  int       i;

  init_index(a);
  i = 0;
  min = find_min(a);
  while(min)
  {
    min->index = i ;
    i++;
    min = find_min(a);
  }
}