#include <push_swap.h>

void    adaptive_sort(t_stack **a, t_stack **b, t_config *cfg, t_bench *bench)
{
    cfg->disorder = compute_disorder(*a);

    if (cfg->disorder < 0.2)
        simple_sort(a, b, bench);
    else if (cfg->disorder < 0.5)
        medium_sort(a, b,bench);
    else
    {
        normalize(*a);
        radix_sort(a, b, bench);
    }
}
