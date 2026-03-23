#include <push_swap.h>

void    adaptive_sort(t_stack **a, t_stack **b, t_config *cfg, t_bench *bench, int print_on)
{
    cfg->disorder = compute_disorder(*a);

    if (cfg->disorder < 0.2)
        simple_sort(a, b, bench,print_on);
    else if (cfg->disorder < 0.5)
        medium_sort(a, b,bench,print_on);
    else
    {
        normalize(*a);
        radix_sort(a, b, bench,print_on);
    }
}
