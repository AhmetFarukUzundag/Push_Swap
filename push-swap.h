#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	int			    data;
	struct s_node	*next;
}				t_node;

void sa(t_node **a);

#endif