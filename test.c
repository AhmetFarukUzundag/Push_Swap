typedef struct s_node
{
	int 			data;
	struct s_node 	*next;
} t_node;


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

int main(void)
{
	t_node *top = NULL;
	top->data = 42;
}
