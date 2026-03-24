/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 21:18:32 by haydinog          #+#    #+#             */
/*   Updated: 2026/03/24 17:29:46 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_strategy_name(t_strategy strategy)
{
	if (strategy == STRAT_SIMPLE)
		return ("Simple");
	if (strategy == STRAT_MEDIUM)
		return ("Medium");
	if (strategy == STRAT_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

static char	*get_complexity(t_strategy strategy, double disorder, int size)
{
	if (strategy == STRAT_SIMPLE)
		return ("O(n^2)");
	if (strategy == STRAT_MEDIUM)
		return ("O(n√n)");
	if (strategy == STRAT_COMPLEX)
		return ("O(n log n)");
	if (size <= 5)
		return ("O(n^2)");
	if (size <= 100)
		return (disorder < 0.3 ? "O(n^2)" : "O(n√n)");
	return (disorder < 0.5 ? "O(n√n)" : "O(n log n)");
}

static void	print_ops1(t_bench *b)
{
	putstr("[bench] sa: ");
	putnbr(b->sa);
	putstr(" sb: ");
	putnbr(b->sb);
	putstr(" ss: ");
	putnbr(b->ss);
	putstr(" pa: ");
	putnbr(b->pa);
	putstr(" pb: ");
	putnbr(b->pb);
	putendl("");
}

static void	print_ops2(t_bench *b)
{
	putstr("[bench] ra: ");
	putnbr(b->ra);
	putstr(" rb: ");
	putnbr(b->rb);
	putstr(" rr: ");
	putnbr(b->rr);
	putstr(" rra: ");
	putnbr(b->rra);
	putstr(" rrb: ");
	putnbr(b->rrb);
	putstr(" rrr: ");
	putnbr(b->rrr);
	putendl("");
}

void	bench_print(t_config *cfg, t_bench *b)
{
	if (!cfg || !b || !cfg->bench_enabled)
		return ;
	putstr("[bench] disorder: ");
	put_percent(cfg->disorder);
	putendl("");
	putstr("[bench] strategy: ");
	putstr(get_strategy_name(cfg->strategy));
	putstr(" / ");
	putendl(get_complexity(cfg->strategy, cfg->disorder, cfg->size));
	putstr("[bench] total_op: ");
	putnbr(b->total);
	putendl("");
	print_ops1(b);
	print_ops2(b);
}
