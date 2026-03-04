typedef struct s_node
{
	int			data;
	struct push	*next;
}				t_node;

// int stack[100];
// int top = -1;

// void push(int x) {
//     stack[++top] = x;
// }

// int pop() {
//     return (stack[top--]);
// }

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_node *top = NULL;
	top->data = 42;
}
