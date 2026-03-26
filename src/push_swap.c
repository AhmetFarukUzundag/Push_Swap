/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzundag <auzundag@student.42istanbul.com.tr  + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:59:16 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/26 11:45:32 by auzundag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_strategy_flag(const char *arg, t_config *cfg, int *seen)
{
	if ((ft_strncmp(arg, "--simple", 8) == 0) && arg[8] == '\0')
		cfg->strategy = STRAT_SIMPLE;
	else if ((ft_strncmp(arg, "--medium", 8) == 0) && arg[8] == '\0')
		cfg->strategy = STRAT_MEDIUM;
	else if ((ft_strncmp(arg, "--complex", 9) == 0) && arg[9] == '\0')
		cfg->strategy = STRAT_COMPLEX;
	else if ((ft_strncmp(arg, "--adaptive", 10) == 0) && arg[10] == '\0')
		cfg->strategy = STRAT_ADAPTIVE;
	else
		return (0);
	if (*seen)
		return (0);
	*seen = 1;
	return (1);
}

static int	handle_flag(const char *arg, t_config *cfg, int *strategy_seen,
		int *bench_seen)
{
	if ((ft_strncmp(arg, "--bench", 7) == 0) && arg[7] == '\0')
	{
		if (*bench_seen)
			return (0);
		*bench_seen = 1;
		cfg->bench_enabled = 1;
		return (1);
	}
	return (set_strategy_flag(arg, cfg, strategy_seen));
}

int	parse_flags(int argc, char **argv, t_config *cfg, int *first_num_idx)
{
	int	i;
	int	strategy_seen;
	int	bench_seen;

	cfg->strategy = STRAT_ADAPTIVE;
	cfg->bench_enabled = 0;
	strategy_seen = 0;
	bench_seen = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!handle_flag(argv[i], cfg, &strategy_seen, &bench_seen))
			return (0);
		i++;
	}
	*first_num_idx = i;
	return (1);
}

static void	strategy_selector(t_config *cfg, t_stack **a, t_stack **b,
		t_bench *bench)
{
	cfg->size = stack_size(*a);
	if (cfg->strategy == STRAT_SIMPLE)
		simple_sort(a, b, bench, cfg);
	else if (cfg->strategy == STRAT_MEDIUM)
		medium_sort(a, b, bench, cfg);
	else if (cfg->strategy == STRAT_COMPLEX)
	{
		normalize(*a);
		radix_sort(a, b, bench, cfg);
	}
	else
		adaptive_sort(a, b, cfg, bench);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_config	cfg;
	t_bench		bench;
	int			first_num;

	b = NULL;
	if (argc < 2)
		return (0);
	bench_init(&bench);
	if (!parse_flags(argc, argv, &cfg, &first_num))
		return (write(2, "Error\n", 6), 0);
	if (first_num >= argc)
		return (0);
	if (!parser_arguments(argc - first_num, &argv[first_num], &a))
		return (0);
	cfg.size = stack_size(a);
	cfg.disorder = compute_disorder(a);
	if (is_sorted(a))
		return (free_stack(&a), 0);
	strategy_selector(&cfg, &a, &b, &bench);
	if (cfg.bench_enabled)
		bench_print(&cfg, &bench);
	return (free_stack(&a), 0);
}
