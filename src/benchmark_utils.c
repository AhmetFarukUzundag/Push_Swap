/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bencmark_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.com.tr>  #+#  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-24 11:44:53 by haydinog          #+#    #+#             */
/*   Updated: 2026-03-24 11:44:53 by haydinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr(char *s)
{
	while (*s)
		write(2, s++, 1);
}

void	putnbr(long n)
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

void	putendl(char *s)
{
	putstr(s);
	write(2, "\n", 1);
}

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

void	put_percent(double d)
{
	int	full;
	int	frac;

	full = (int)(d * 100);
	frac = (int)(d * 10000) % 100;
	putnbr(full);
	write(2, ".", 1);
	if (frac < 10)
		write(2, "0", 1);
	putnbr(frac);
	putstr("%");
}
