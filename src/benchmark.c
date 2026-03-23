/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 21:18:32 by haydinog          #+#    #+#             */
/*   Updated: 2026/03/23 22:15:42 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_init(t_bench *b)
{
	b->total = 0;
	b->sa = 0;
	b->sb = 0;
	b->ss = 0;
	b->pa = 0;
	b->pb = 0;
	b->ra = 0;
	b->rb = 0;
	b->rr = 0;
	b->rra = 0;
	b->rrb = 0;
	b->rrr = 0;
}

static void	putstr(char *s)
{
	while (*s)
		write(2, s++, 1);
}

static void	putnbr(long n)
{
	char	c;

	if (n < 0)
	{
		write(2, "-", 1); 
		n = -n;
	}
	if (n >= 10)
		putnbr(n / 10);
	c = (n % 10) + '0';
	write(2, &c, 1);
}

static void	putendl(char *s)
{
	putstr(s);
	write(2, "\n", 1);
}


static void	put_percent(double d) // disorder değerini %ye ceviriyor 0.49 ise %49 yapıyor
{
	putnbr((int)(d * 100));
	putstr("%");
}

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
static char	*get_complexity(t_strategy strategy, double disorder)
{
	if (strategy == STRAT_SIMPLE)
		return ("O(n^2)");
	if (strategy == STRAT_MEDIUM)
		return ("O(n√n)");
	if (strategy == STRAT_COMPLEX)
		return ("O(n log n)");
	if (disorder < 0.2)
		return ("O(n^2)");
	if (disorder < 0.5)
		return ("O(n√n)");
	return ("O(n log n)");
}
void	bench_print(t_config *cfg, t_bench *b)
{
	if (!cfg->bench_enabled)
		return ;
	putstr("[bench] disorder: ");
	put_percent(cfg->disorder);
	putendl("");
	putstr("[bench] strategy: ");
	putstr(get_strategy_name(cfg->strategy));
	putstr(" / ");
	putendl(get_complexity(cfg->strategy, cfg->disorder));
	putstr("[bench] total_op: ");
	putnbr(b->total);
	putendl("");
}