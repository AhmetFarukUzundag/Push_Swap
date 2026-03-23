/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydinog <haydinog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:59:16 by auzundag          #+#    #+#             */
/*   Updated: 2026/03/23 22:45:25 by haydinog         ###   ########.fr       */
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
    if (*seen) // eğer daha önce flag görüldüye 0 return eder
        return (0);
    *seen = 1;
    return (1);
}

static int	handle_flag(const char *arg, t_config *cfg,
                        int *strategy_seen, int *bench_seen)
{
    if ((ft_strncmp(arg, "--bench", 7) == 0) && arg[7] == '\0')
    {
        if (*bench_seen)
            return (0);
        *bench_seen = 1; // --bench flagi varsa bench_seen'i 1 olarak set et (bench görüldü)
        cfg->bench_enabled = 1; // bench_enabled (bench var)
        return (1);
    }
    return (set_strategy_flag(arg, cfg, strategy_seen)); // eşleşmediyse strateji flag'i var mı diye kontrol (--simple, --medium...)
}

int	parse_flags(int argc, char **argv, t_config *cfg, int *first_num_idx)
{
    int	i;
    int	strategy_seen;
    int	bench_seen;

    cfg->strategy = STRAT_ADAPTIVE; // default ayar
    cfg->bench_enabled = 0; // başlangıçta hepsi 0, çünkü henüz hiç bir flag görülmedi
    strategy_seen = 0;
    bench_seen = 0;
    i = 1;
    while (i < argc && argv[i][0] == '-' && argv[i][1] == '-') // argv[1] ->  --bench --simple  -- ilk iki index '--' ise
    {
        if (!handle_flag(argv[i], cfg, &strategy_seen, &bench_seen))
            return (0);
        i++;
    }
    *first_num_idx = i; // flaglerden sonra sayıların başladığı yeri tutar örn: (./push_swap --bench --simple 1 2 3...) i = 3
    return (1);			// eğer hiç bir flag bulunamazsa başlangıç indexini yine i'ye set eder. örn: (./push_swap 1 2 3) i = 1
}

static void	strategy_selector(t_config *cfg, t_stack **a, t_stack **b, t_bench *bench)
{
    if (cfg->strategy == STRAT_SIMPLE)
        simple_sort(a, b,bench);
    else if (cfg->strategy == STRAT_MEDIUM)
        medium_sort(a, b,bench);
    else if (cfg->strategy == STRAT_COMPLEX)
    {
        normalize(*a);
        radix_sort(a, b, bench);
    }
    else
        adaptive_sort(a, b, cfg, bench);
}

int main(int argc, char **argv)
{
    t_stack	 *a;
    t_stack	 *b;
    t_config cfg;
	t_bench		bench;
    int		 first_num;

    b = NULL;
    if (argc < 2)
	{
        return (0);
	}
	bench_init(&bench); // benchin setini 0 a cekiyorum
    if (!parse_flags(argc, argv, &cfg, &first_num)) 
	/*
	Aynı strateji flag’i birden fazla (veya birden fazla farklı strateji)
	--bench birden fazla
	Tanınmayan --foo gibi bir flag*/
        return (write(2, "Error\n", 6), 0);

    if (first_num >= argc)
        return (0); // sadece flag geldi, sayı yok -> hiçbir şey yapma

    if (!parser_arguments(argc - first_num, &argv[first_num], &a)) // argümanların ilk başladığı yeri gönderiyorum (sayı)
        return (0); // parser zaten Error basıyor 

    if (is_sorted(a))
        return (free_stack(&a), 0);

	strategy_selector(&cfg, &a, &b);

	strategy_selector(&cfg, &a, &b); // algo seçildi
	if (cfg.bench_enabled) // bench aktifse bench fonksiyonunu çağır
		// bench_print(&cfg, parameters...);

    free_stack(&a);
    return (0);
}
