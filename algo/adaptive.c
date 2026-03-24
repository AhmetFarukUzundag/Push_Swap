/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:19:24 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/24 17:29:46 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	adaptive_sort(t_stack **a, t_stack **b, t_config *cfg, t_bench *bench)
{
	cfg->size = stack_size(*a);
	cfg->disorder = compute_disorder(*a);
	if (cfg->size <= 5)
		simple_sort(a, b, bench, cfg);
	else if (cfg->size <= 100)
	{
		if (cfg->disorder < 0.3)
			simple_sort(a, b, bench, cfg);
		else
			medium_sort(a, b, bench, cfg);
	}
	else
	{
		if (cfg->disorder < 0.5)
			medium_sort(a, b, bench, cfg);
		else
		{
			normalize(*a);
			radix_sort(a, b, bench, cfg);
		}
	}
}
