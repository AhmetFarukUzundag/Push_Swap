#include "push-swap.h"


void ra(t_node **a) 
{
    t_node *first;
    t_node *last;

    first = *a;
    *a = first->next; 

    last = *a;
    while(last->next) // first->next var mı
        last = last->next; // sonu tutuyor
    last->next = first;
    first->next = NULL;
    // head -> son
}

void rb(t_node **b) 
{
    t_node *first;
    t_node *last;

    first = *b;
    *b = first->next; 

    last = *b;
    while(last->next) // first->next var mı
        last = last->next; // sonu tutuyor
    last->next = first;
    first->next = NULL;
    // head -> son
}
