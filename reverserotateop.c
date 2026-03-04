#include "push-swap.h"

void rra(t_node **a)
{
    t_node *last;
    t_node *prev;

    if (!a || !*a || !(*a)->next)
        return;
    prev = NULL;
    last = *a;

    while(last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *a;
    printf("rra\n");
}
void rrb(t_node **b)
{
    t_node *last;
    t_node *prev;

    if (!b || !*b || !(*b)->next)
        return;
    prev = NULL;
    last = *b;

    while(last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *b;
    printf("rrb\n");
}

void rrr(t_node **a, t_node **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    printf("rrr\n");
}