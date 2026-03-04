#include "push-swap.h"

void pa(t_node **a, t_node **b)
{
    t_node *temp;

    temp = *a;
    *a = (*a)->next; //a'nın 2.
    temp->next = *b; //head'i b ye bagladım
    *b = temp;
    printf("pa");
}
void pb(t_node **b, t_node **a)
{
    t_node *temp;

    temp = *b;
    *b = (*b)->next; //a'nın 2.
    temp->next = *a; //head'i b ye bagladım
    *a = temp;
    printf("pb");
}