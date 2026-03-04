#include "push-swap.h"

void swap(t_node **stack)
{
    t_node *first;
    t_node *second;

    if(!*stack || !(*stack)->next)
        return ;
    first = *stack;
    second = first->next; // 2

    first->next = second->next; // 3
    second->next = first; // 3->1
    *stack = second; // 1 -> 2
}
void sa(t_node **a)
{
    swap(a);
    printf("sa");
}
void sb(t_node **b)
{
    swap(b);
    printf("sb");
}
void ss(t_node **a, t_node **b)
{
    swap(a);
    swap(b);
    printf("ss");
}