/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.com.tr>  #+#  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-17 11:57:33 by haydinog          #+#    #+#             */
/*   Updated: 2026-03-17 11:57:33 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_index(t_stack *a) // indexlerini -1 veriyorum
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
static int find_big_index(t_stack *a) // en büyük indexi buluyorumh
{
    int max_index;
    t_stack *tmp;

    if (!a)
        return(0);
    tmp = a;
    max_index = tmp->index;
    while(tmp)
    {
        if(max_index < tmp->index)
            max_index = tmp->index;
        tmp = tmp->next; 
    }
    return(max_index);
}
int how_many_bits(t_stack *a) // en büyük indexin kaç bit oldugunu buluyorumh
{
    int max;
    int bits;

    bits = 0;
    max = find_big_index(a);

    while (max != 0)
    {
      max = max >> 1;
      bits++;
    }
    return(bits);
}
